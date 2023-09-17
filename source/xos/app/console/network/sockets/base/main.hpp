//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2023 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 9/7/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HPP

#include "xos/app/console/network/sockets/base/main_opt.hpp"

#include "xos/network/sockets/os/interfaces.hpp"
#include "xos/network/sockets/os/interface.hpp"
#include "xos/network/sockets/interface.hpp"
#include "xos/network/sockets/reader.hpp"
#include "xos/network/sockets/writer.hpp"

#include "xos/network/sockets/ip/v4/endpoint.hpp"
#include "xos/network/sockets/ip/v4/tcp/transport.hpp"
#include "xos/network/sockets/ip/v4/udp/transport.hpp"

#if !defined(WINSOCK_1)
#include "xos/network/sockets/ip/v6/endpoint.hpp"
#include "xos/network/sockets/ip/v6/tcp/transport.hpp"
#include "xos/network/sockets/ip/v6/udp/transport.hpp"
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::network::sockets::base::main_optt<>,  class TImplements = typename TExtends::implements>

class maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint(): run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...sockets_run
    virtual int before_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::network::sockets::os::interfaces sockets;

        LOGGER_IS_LOGGED_INFO("sockets.startup()...");
        if (!(sockets.startup())) {
            LOGGER_IS_LOGGED_ERROR("...failed on sockets.startup()");
            err = 1;
        } else {
            LOGGER_IS_LOGGED_INFO("...sockets.startup()");
        }
        return err;
    }
    virtual int after_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::network::sockets::os::interfaces sockets;

        LOGGER_IS_LOGGED_INFO("sockets.cleanup()...");
        if (!(sockets.cleanup())) {
            LOGGER_IS_LOGGED_ERROR("...failed on sockets.cleanup()");
            err = 1;
        } else {
            LOGGER_IS_LOGGED_INFO("...sockets.cleanup()");
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...accept(int argc, ...)
    virtual int accept(int argc, char_t** argv, char_t**env) {
        int err = 0;
        const xos::network::sockets::sockstring_t& host = this->accept_host();
        const xos::network::sockets::sockport_t& port = this->accept_port();
        xos::network::sockets::endpoint& ep = this->accept_ep();
        xos::network::sockets::transport& tp = this->accept_tp();
        xos::network::sockets::interface &ac = this->accept_iface(), 
                                         &cn = this->connect_iface();
        xos::network::sockets::sockaddr_t& ad = this->connect_addr();
        xos::network::sockets::socklen_t& al = this->connect_addrlen();

        LOGGER_IS_LOGGED_INFO("ep.attach(host = \"" << host << "\", port = " << unsigned_to_string(port) << ")...");
        if ((ep.attach(host, port))) {
            LOGGER_IS_LOGGED_INFO("...ep.attach(host = \"" << host << "\", port = " << unsigned_to_string(port) << ")");

            LOGGER_IS_LOGGED_INFO("ac.open(tp)...");
            if ((ac.open(tp))) {
                LOGGER_IS_LOGGED_INFO("...ac.open(tp)");
                
                LOGGER_IS_LOGGED_INFO("ac.listen(ep)...");
                if ((ac.listen(ep))) {
                    LOGGER_IS_LOGGED_INFO("...ac.listen(ep)");
                    
                    do {
                        LOGGER_IS_LOGGED_INFO("ac.accept(cn, &ad, al)...");
                        if ((ac.accept(cn, &ad, al))) {
                            LOGGER_IS_LOGGED_INFO("...ac.accept(cn, &ad, al)");
                            
                            all_accept(cn, argc, argv, env);
                            LOGGER_IS_LOGGED_INFO("cn.close()...");
                            cn.close();
                        }
                    } while (!(this->accept_one() || this->accept_done() || this->accept_restart()));
                }
                LOGGER_IS_LOGGED_INFO("ac.close()...");
                ac.close();
            }
            LOGGER_IS_LOGGED_INFO("ep.detach()...");
            ep.detach();
        }
        return err;
    }

    /// ...accept(xos::network::sockets::interface& cn, ...)
    virtual int accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_recv_request(cn, argc, argv, env))) {
            if (!(err = this->all_send_response(cn, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int before_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_accept(cn, argc, argv, env))) {
            int err2 = 0;
            err = accept(cn, argc, argv, env);
            if ((err2 = after_accept(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...connect(int argc, ...)
    virtual int connect(int argc, char_t** argv, char_t**env) {
        int err = 0;
        const xos::network::sockets::sockstring_t& host = this->connect_host();
        const xos::network::sockets::sockport_t& port = this->connect_port();
        xos::network::sockets::endpoint& ep = this->connect_ep();
        xos::network::sockets::transport& tp = this->connect_tp();
        xos::network::sockets::interface &cn = this->connect_iface();

        LOGGER_IS_LOGGED_INFO("ep.attach(host = \"" << host.chars() << "\", port = " << unsigned_to_string(port).chars() << ")...");
        if (!(ep.attach(host, port))) {
            LOGGER_IS_LOGGED_ERROR("...failed on ep.attach(host = \"" << host.chars() << "\", port = " << unsigned_to_string(port).chars() << ")...");
        } else {
            LOGGER_IS_LOGGED_INFO("...ep.attach(host = \"" << host.chars() << "\", port = " << unsigned_to_string(port).chars() << ")");

            LOGGER_IS_LOGGED_INFO("cn.open(tp)...");
            if (!(cn.open(tp))) {
                LOGGER_IS_LOGGED_ERROR("...failed on ");
            } else {
                LOGGER_IS_LOGGED_INFO("...cn.open(tp)");
                
                LOGGER_IS_LOGGED_INFO("cn.connect(ep)...");
                if (!(cn.connect(ep))) {
                    LOGGER_IS_LOGGED_ERROR("...failed on ");
                } else {
                    LOGGER_IS_LOGGED_INFO("...cn.connect(ep)");
                    
                    this->all_connect(cn, argc, argv, env);
                }
                LOGGER_IS_LOGGED_INFO("cn.close()...");
                cn.close();
            }
            LOGGER_IS_LOGGED_INFO("ep.detach()...");
            ep.detach();
        }
        return err;
    }

    /// ...connect(xos::network::sockets::interface& cn, ...)
    virtual int connect(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_send_request(cn, argc, argv, env))) {
            if (!(err = this->all_recv_response(cn, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int before_connect(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_connect(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_connect(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_connect(cn, argc, argv, env))) {
            int err2 = 0;
            err = connect(cn, argc, argv, env);
            if ((err2 = after_connect(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...send(int argc, ...)
    virtual int send(int argc, char_t** argv, char_t**env) {
        int err = 0;
        const xos::network::sockets::sockstring_t& host = this->connect_host();
        const xos::network::sockets::sockport_t& port = this->connect_port();
        xos::network::sockets::endpoint& ep = this->connect_ep();
        xos::network::sockets::transport& tp = this->send_tp();
        xos::network::sockets::interface &cn = this->connect_iface();

        LOGGER_IS_LOGGED_INFO("ep.attach(host = \"" << host.chars() << "\", port = " << unsigned_to_string(port).chars() << ")...");
        if (!(ep.attach(host, port))) {
            LOGGER_IS_LOGGED_ERROR("...failed on ep.attach(host = \"" << host.chars() << "\", port = " << unsigned_to_string(port).chars() << ")...");
        } else {
            LOGGER_IS_LOGGED_INFO("...ep.attach(host = \"" << host.chars() << "\", port = " << unsigned_to_string(port).chars() << ")");

            LOGGER_IS_LOGGED_INFO("cn.open(tp)...");
            if (!(cn.open(tp))) {
                LOGGER_IS_LOGGED_ERROR("...failed on ");
            } else {
                LOGGER_IS_LOGGED_INFO("...cn.open(tp)");
                
                if (!(err = all_send_to(ep, cn, argc, argv, env))) {
                } else {
                }
                LOGGER_IS_LOGGED_INFO("cn.close()...");
                cn.close();
            }
            LOGGER_IS_LOGGED_INFO("ep.detach()...");
            ep.detach();
        }
        return err;
    }

    /// ...send_to(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, ...)
    virtual int send_to(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        string_t& message = this->message_sent();
        if (!(err = all_send_message_to(ep, cn, message, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_send_to(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_to(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_to(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_send_to(ep, cn, argc, argv, env))) {
            int err2 = 0;
            err = send_to(ep, cn, argc, argv, env);
            if ((err2 = after_send_to(ep, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...receive(int argc, ...)
    virtual int receive(int argc, char_t** argv, char_t**env) {
        int err = 0;
        const xos::network::sockets::sockstring_t& host = this->accept_host();
        const xos::network::sockets::sockport_t& port = this->accept_port();
        xos::network::sockets::endpoint& ep = this->accept_ep();
        xos::network::sockets::transport& tp = this->receive_tp();
        xos::network::sockets::interface &ac = this->accept_iface();

        LOGGER_IS_LOGGED_INFO("ep.attach(host = \"" << host << "\", port = " << unsigned_to_string(port) << ")...");
        if ((ep.attach(host, port))) {
            LOGGER_IS_LOGGED_INFO("...ep.attach(host = \"" << host << "\", port = " << unsigned_to_string(port) << ")");

            LOGGER_IS_LOGGED_INFO("ac.open(tp)...");
            if ((ac.open(tp))) {
                LOGGER_IS_LOGGED_INFO("...ac.open(tp)");
                
                LOGGER_IS_LOGGED_INFO("ac.bind(ep)...");
                if ((ac.bind(ep))) {
                    LOGGER_IS_LOGGED_INFO("...ac.bind(ep)");
                    
                    do {
                        LOGGER_IS_LOGGED_INFO("!(err = all_receive_from(ep, ac, argc, argv, env))...");
                        if (!(err = all_receive_from(ep, ac, argc, argv, env))) {
                            LOGGER_IS_LOGGED_INFO("...!(err = all_receive_from(ep, ac, argc, argv, env))");
                        } else {
                            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_receive_from(ep, ac, argc, argv, env))");
                        }
                    } while (!(this->accept_one() || this->accept_done() || this->accept_restart()));
                }
                LOGGER_IS_LOGGED_INFO("ac.close()...");
                ac.close();
            }
            LOGGER_IS_LOGGED_INFO("ep.detach()...");
            ep.detach();
        }
        return err;
    }

    /// ...receive_from(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, ...)
    virtual int receive_from(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        string_t& message = this->message_received();
        if (!(err = all_receive_message_from(ep, cn, message, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_receive_from(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_from(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_from(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_receive_from(ep, cn, argc, argv, env))) {
            int err2 = 0;
            err = receive_from(ep, cn, argc, argv, env);
            if ((err2 = after_receive_from(ep, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// 
    /// ..send / ...recv / ...relay request
    /// ...
    /// ...send_request
    virtual int send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        string_t& request = this->request();
        err = this->all_send_request(cn, request, argc, argv, env);
        return err;
    }
    virtual int before_send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_send_request(cn, argc, argv, env))) {
            int err2 = 0;
            err = send_request(cn, argc, argv, env);
            if ((err2 = after_send_request(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...recv_request
    virtual int recv_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        string_t& request = this->request();
        err = this->all_recv_request(request, cn, argc, argv, env);
        return err;
    }
    virtual int before_recv_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_recv_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_recv_request(cn, argc, argv, env))) {
            int err2 = 0;
            err = recv_request(cn, argc, argv, env);
            if ((err2 = after_recv_request(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...relay_request
    virtual int relay_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_relay_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_relay_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_relay_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_relay_request(cn, argc, argv, env))) {
            int err2 = 0;
            err = relay_request(cn, argc, argv, env);
            if ((err2 = after_relay_request(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ..send / ...recv / ...relay request
    /// 

    /// 
    /// ..send / ...recv / ...relay response
    /// ...
    /// ...send_response
    virtual int send_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        string_t& response = this->response();
        err = this->all_send_response(cn, response, argc, argv, env);
        return err;
    }
    virtual int before_send_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_send_response(cn, argc, argv, env))) {
            int err2 = 0;
            err = send_response(cn, argc, argv, env);
            if ((err2 = after_send_response(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...recv_response
    virtual int recv_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        string_t& response = this->response();
        err = this->all_recv_response(response, cn, argc, argv, env);
        return err;
    }
    virtual int before_recv_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_recv_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_recv_response(cn, argc, argv, env))) {
            int err2 = 0;
            err = recv_response(cn, argc, argv, env);
            if ((err2 = after_recv_response(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...relay_response
    virtual int relay_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_relay_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_relay_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_relay_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_relay_response(cn, argc, argv, env))) {
            int err2 = 0;
            err = relay_response(cn, argc, argv, env);
            if ((err2 = after_relay_response(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ..send / ...recv / ...relay response
    /// 

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    ///
    /// ...send / ...recv request
    /// ...
    /// ...send_request
    virtual int send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;

        if (!(err = all_prepare_request(request, cn, argc, argv, env))) {
            size_t length = 0;
            const char_t* chars = 0;
    
            if ((chars = request.has_chars(length))) {
                cn.send(chars, length);
            }
        }
        return err;
    }
    virtual int before_send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_request(cn, request, argc, argv, env))) {
            int err2 = 0;
            err = send_request(cn, request, argc, argv, env);
            if ((err2 = after_send_request(cn, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...recv_request
    virtual int recv_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;

        request.clear();
        if (!(err = this->recv_crlf2(request, c, cn, argc, argv, env))) {
            err = all_process_request(request, cn, argc, argv, env);
        }
        return err;
    }
    virtual int before_recv_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_recv_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_recv_request(request, cn, argc, argv, env))) {
            int err2 = 0;
            err = recv_request(request, cn, argc, argv, env);
            if ((err2 = after_recv_request(request, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...send / ...recv request
    /// 

    ///
    /// ...send / ...recv response
    /// ...
    /// ...send_response
    virtual int send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        
        if (!(err = all_prepare_response(response, cn, argc, argv, env))) {
            size_t length = 0;
            const char_t* chars = 0;
    
            if ((chars = response.has_chars(length))) {
                cn.send(chars, length);
            }
        }
        return err;
    }
    virtual int before_send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_response(cn, response, argc, argv, env))) {
            int err2 = 0;
            err = send_response(cn, response, argc, argv, env);
            if ((err2 = after_send_response(cn, response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...recv_response
    virtual int recv_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;

        response.clear();
        if (!(err = this->recv_crlf2(response, c, cn, argc, argv, env))) {
            err = all_process_response(response, cn, argc, argv, env);
        }
        return err;
    }
    virtual int before_recv_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_recv_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_recv_response(response, cn, argc, argv, env))) {
            int err2 = 0;
            err = recv_response(response, cn, argc, argv, env);
            if ((err2 = after_recv_response(response, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...send / ...recv response
    /// 

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...send_message_to
    virtual int send_message_to(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;

        if (!(err = all_prepare_message_send_to(message, ep, cn, argc, argv, env))) {
            size_t length = 0;
            const char_t* chars = 0;
    
            LOGGER_IS_LOGGED_INFO("(chars = message.has_chars(length))...");
            if ((chars = message.has_chars(length))) {
                ssize_t count = 0;
                
                LOGGER_IS_LOGGED_INFO("...(chars = message.has_chars(" << length << "))");
                LOGGER_IS_LOGGED_INFO("(0 < (count = cn.sendto(chars, length, 0, ep)))...");
                if (0 < (count = cn.sendto(chars, length, 0, ep))) {
                    LOGGER_IS_LOGGED_INFO("...(0 < (" << count << " = cn.sendto(chars, length, 0, ep)))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed (0 < (" << count << " = cn.sendto(chars, length, 0, ep)))");
                }
            }
        }
        return err;
    }
    virtual int before_send_message_to(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_message_to(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_message_to(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_message_to(ep, cn, message, argc, argv, env))) {
            int err2 = 0;
            err = send_message_to(ep, cn, message, argc, argv, env);
            if ((err2 = after_send_message_to(ep, cn, message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...receive_message_from
    virtual int receive_message_from(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t size = 0;
        char_t* chars = 0;
        
        LOGGER_IS_LOGGED_INFO("(chars = &this->message_chars(size))...");
        if ((chars = &this->message_chars(size))) {
            ssize_t count = 0;

            LOGGER_IS_LOGGED_INFO("...(chars = &this->message_chars(" << size << "))");
            LOGGER_IS_LOGGED_INFO("message.clear()...");
            message.clear();

            LOGGER_IS_LOGGED_INFO("(0 < (count = cn.recvfrom(chars, " << size << ", 0, ep)))...");
            if (0 < (count = cn.recvfrom(chars, size, 0, ep))) {
                LOGGER_IS_LOGGED_INFO("...(0 < (" << count << " = cn.recvfrom(chars, " << size << ", 0, ep)))");
                LOGGER_IS_LOGGED_INFO("message.append(chars, " << count << ")...");
                message.append(chars, count);
                
                LOGGER_IS_LOGGED_INFO("!(err = all_prepare_message_receive_from(message, ep, cn, argc, argv, env))...");
                if (!(err = all_prepare_message_receive_from(message, ep, cn, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_message_receive_from(message, ep, cn, argc, argv, env))");

                    LOGGER_IS_LOGGED_INFO("!(err = all_process_message_receive_from(message, ep, cn, argc, argv, env))...");
                    if (!(err = all_process_message_receive_from(message, ep, cn, argc, argv, env))) {
                        LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_message_receive_from(message, ep, cn, argc, argv, env))");
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = all_process_message_receive_from(message, ep, cn, argc, argv, env))");
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = all_prepare_message_receive_from(message, ep, cn, argc, argv, env))");
                }
            } else {
                if (0 > count) {
                    LOGGER_IS_LOGGED_INFO("...failed on (0 < (" << count << " = cn.recvfrom(chars, size, 0, ep)))");
                }
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (chars = &this->message_chars(size))");
        }
        return err;
    }
    virtual int before_receive_message_from(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_message_from(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_message_from(xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_message_from(ep, cn, message, argc, argv, env))) {
            int err2 = 0;
            err = receive_message_from(ep, cn, message, argc, argv, env);
            if ((err2 = after_receive_message_from(ep, cn, message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    ///
    /// ...prepare_request
    /// ...
    virtual int prepare_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_request(request, cn, argc, argv, env))) {
            int err2 = 0;
            err = prepare_request(request, cn, argc, argv, env);
            if ((err2 = after_prepare_request(request, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...prepare_request
    /// 

    ///
    /// ...prepare_response
    /// ...
    virtual int prepare_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response(response, cn, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response(response, cn, argc, argv, env);
            if ((err2 = after_prepare_response(response, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...prepare_response
    /// 

    ///
    /// ...process_request
    /// ...
    virtual int process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = request.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_request(request, cn, argc, argv, env))) {
            int err2 = 0;
            err = process_request(request, cn, argc, argv, env);
            if ((err2 = after_process_request(request, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...process_request
    /// 

    ///
    /// ...process_response
    /// ...
    virtual int process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = response.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response(response, cn, argc, argv, env))) {
            int err2 = 0;
            err = process_response(response, cn, argc, argv, env);
            if ((err2 = after_process_response(response, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...process_response
    /// 

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    ///
    /// ...prepare_message_send_to
    /// ...
    virtual int prepare_message_send_to(string_t& message, xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_message_send_to(string_t& message, xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_message_send_to(string_t& message, xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_message_send_to(string_t& message, xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_message_send_to(message, ep, cn, argc, argv, env))) {
            int err2 = 0;
            err = prepare_message_send_to(message, ep, cn, argc, argv, env);
            if ((err2 = after_prepare_message_send_to(message, ep, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...prepare_message_sent
    /// 

    ///
    /// ...prepare_message_receive_from
    /// ...
    virtual int prepare_message_receive_from(string_t& message, xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_message_receive_from(string_t& message, xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_message_receive_from(string_t& message, xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_message_receive_from(string_t& message, xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_message_receive_from(message, ep, cn, argc, argv, env))) {
            int err2 = 0;
            err = prepare_message_receive_from(message, ep, cn, argc, argv, env);
            if ((err2 = after_prepare_message_receive_from(message, ep, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...prepare_message_sent
    /// 

    ///
    /// ...process_message_receive_from
    /// ...
    virtual int process_message_receive_from(string_t& message, xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = message.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_process_message_receive_from(string_t& message, xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_message_receive_from(string_t& message, xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_message_receive_from(string_t& message, xos::network::sockets::endpoint& ep, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_message_receive_from(message, ep, cn, argc, argv, env))) {
            int err2 = 0;
            err = process_message_receive_from(message, ep, cn, argc, argv, env);
            if ((err2 = after_process_message_receive_from(message, ep, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...process_message_receive_from
    /// 

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// send
    /// ...
    /// send_lf...
    /// ...<lf>
    virtual int send_lf(xos::network::sockets::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        string_t lf_s(s);
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        lf_s.appendlf();
        if ((chars = lf_s.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    /// send_cr...
    /// ...<cr>
    virtual int send_cr(xos::network::sockets::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        string_t cr_s(s);
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        cr_s.appendcr();
        if ((chars = cr_s.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    /// ...<cr><lf>
    virtual int send_crlf(xos::network::sockets::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        string_t cr_s(s);
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        cr_s.appendcr();
        cr_s.appendlf();
        if ((chars = cr_s.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    /// ...
    /// send

    ///
    /// recv
    /// ...
    /// recv_before_lf...
    /// ...<lf>
    virtual int recv_before_lf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            switch (c) {
            case '\n':
                return err = 0;
            default:
                r.append(&c, 1);
            }
        }
        return err;
    }
    /// recv_lf...
    /// ...<lf>
    virtual int recv_lf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\n':
                return err = 0;
            }
        }
        return err;
    }
    /// recv_before_cr...
    /// ...<cr>
    virtual int recv_before_cr(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            switch (c) {
            case '\r':
                return err = 0;
            default:
                r.append(&c, 1);
            }
        }
        return err;
    }
    /// recv_cr...
    /// ...<cr>
    virtual int recv_cr(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                return err = 0;
            }
        }
        return err;
    }
    /// ...<cr><lf>
    virtual int recv_crlf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr } s = ch;
        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                switch (s) {
                case ch:
                case cr:
                    s = cr;
                    break;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            case '\n':
                switch (s) {
                case ch:
                    s = ch;
                    break;
                case cr:
                    return err = 0;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            default:
                s = ch;
                break;
            }
        }
        return err;
    }
    /// ...<cr><lf><cr><lf>
    virtual int on_recv_crlf2(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int recv_crlf2(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr, lf, lfcr } s = ch;

        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                switch (s) {
                case ch:
                case cr:
                    s = cr;
                    break;
                case lf:
                    s = lfcr;
                    break;
                case lfcr:
                    s = cr;
                    break;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            case '\n':
                switch (s) {
                case ch:
                case lf:
                    s = ch;
                    break;
                case cr:
                    s = lf;
                    break;
                case lfcr:
                    err = on_recv_crlf2(r, c, cn, argc, argv, env);
                    return err;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            default:
                s = ch;
                break;
            }
        }
        return err;
    }
    /// <d>[1..n]...[1..n] | <cr><lf><cr><lf>
    virtual int recv_sizeof_sized_crlf2(size_t size_of, string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        size_t size = 0;

        for (size_t remain = size_of; remain; --remain) {
            if  (1 > (amount = cn.recv(&c, 1))) {
                return err;
            }
            r.append(&c, 1);
            size = (size << 8) | ((uint8_t)c);
        }
        err = recv_sized_crlf2(size, r, c, cn, argc, argv, env);
        return err;
    }
    /// ...[1..n] | <cr><lf><cr><lf>
    virtual int recv_sized_crlf2(size_t size, string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr, lf, lfcr } s = ch;
        for (; size; --size) {
            if (1 > (amount = cn.recv(&c, 1))) {
                break;
            } else {
                r.append(&c, 1);
                switch (c) {
                case '\r':
                    switch (s) {
                    case ch:
                        s = cr;
                        break;
                    case cr:
                        s = cr;
                        break;
                    case lf:
                        s = lfcr;
                        break;
                    case lfcr:
                        s = cr;
                        break;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    }
                    break;
                case '\n':
                    switch (s) {
                    case ch:
                        s = ch;
                        break;
                    case cr:
                        s = lf;
                        break;
                    case lf:
                        s = ch;
                        break;
                    case lfcr:
                        return err = 0;
                        break;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    }
                    break;
                default:
                    s = ch;
                    break;
                }
            }
        }
        return err;
    }
    /// ...
    /// recv
    /// 

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...ep
    xos::network::sockets::endpoint& (derives::*accept_ep_)() const;
    virtual xos::network::sockets::endpoint& accept_ep() const {
        if ((this->accept_ep_)) {
            return (this->*accept_ep_)();
        }
        return this->default_accept_ep();
    }
    virtual xos::network::sockets::endpoint& default_accept_ep() const {
        return this->accept_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& accept_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& accept_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...tp
    xos::network::sockets::transport& (derives::*accept_tp_)() const;
    virtual xos::network::sockets::transport& accept_tp() const {
        if ((this->accept_tp_)) {
            return (this->*accept_tp_)();
        }
        return this->default_accept_tp();
    }
    virtual xos::network::sockets::transport& default_accept_tp() const {
        return this->accept_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& accept_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& accept_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...ep
    xos::network::sockets::endpoint& (derives::*connect_ep_)() const;
    virtual xos::network::sockets::endpoint& connect_ep() const {
        if ((this->connect_ep_)) {
            return (this->*connect_ep_)();
        }
        return this->default_connect_ep();
    }
    virtual xos::network::sockets::endpoint& default_connect_ep() const {
        return this->connect_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& connect_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& connect_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...tp
    xos::network::sockets::transport& (derives::*connect_tp_)() const;
    virtual xos::network::sockets::transport& connect_tp() const {
        if ((this->connect_tp_)) {
            return (this->*connect_tp_)();
        }
        return this->default_connect_tp();
    }
    virtual xos::network::sockets::transport& default_connect_tp() const {
        return this->connect_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& connect_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& connect_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...ep
    xos::network::sockets::endpoint& (derives::*relay_ep_)() const;
    virtual xos::network::sockets::endpoint& relay_ep() const {
        if ((this->relay_ep_)) {
            return (this->*relay_ep_)();
        }
        return this->default_relay_ep();
    }
    virtual xos::network::sockets::endpoint& default_relay_ep() const {
        return this->relay_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& relay_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& relay_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...tp
    xos::network::sockets::transport& (derives::*relay_tp_)() const;
    virtual xos::network::sockets::transport& relay_tp() const {
        if ((this->relay_tp_)) {
            return (this->*relay_tp_)();
        }
        return this->default_relay_tp();
    }
    virtual xos::network::sockets::transport& default_relay_tp() const {
        return this->relay_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& relay_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& relay_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...tp
    xos::network::sockets::transport& (derives::*send_tp_)() const;
    virtual xos::network::sockets::transport& send_tp() const {
        if ((this->send_tp_)) {
            return (this->*send_tp_)();
        }
        return this->default_send_tp();
    }
    virtual xos::network::sockets::transport& default_send_tp() const {
        return this->send_ip_v4_udp_tp();
    }
    virtual xos::network::sockets::transport& send_ip_v4_udp_tp() const {
        return this->ip_v4_udp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& send_ip_v6_udp_tp() const {
        return this->ip_v6_udp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...tp
    xos::network::sockets::transport& (derives::*receive_tp_)() const;
    virtual xos::network::sockets::transport& receive_tp() const {
        if ((this->receive_tp_)) {
            return (this->*receive_tp_)();
        }
        return this->default_receive_tp();
    }
    virtual xos::network::sockets::transport& default_receive_tp() const {
        return this->receive_ip_v4_udp_tp();
    }
    virtual xos::network::sockets::transport& receive_ip_v4_udp_tp() const {
        return this->ip_v4_udp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& receive_ip_v6_udp_tp() const {
        return this->ip_v6_udp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    ///
    /// ...iface / ...addr / ...ep/ ...tp
    /// ...
    /// ...os_iface
    virtual xos::network::sockets::os::interface& accept_os_iface() const {
        return (xos::network::sockets::os::interface&)accept_os_iface_;
    }
    virtual xos::network::sockets::os::interface& connect_os_iface() const {
        return (xos::network::sockets::os::interface&)connect_os_iface_;
    }
    virtual xos::network::sockets::os::interface& relay_os_iface() const {
        return (xos::network::sockets::os::interface&)relay_os_iface_;
    }

    /// ...iface
    virtual xos::network::sockets::interface& accept_iface() const {
        return (xos::network::sockets::interface&)accept_os_iface();
    }
    virtual xos::network::sockets::interface& connect_iface() const {
        return (xos::network::sockets::interface&)connect_os_iface();
    }
    virtual xos::network::sockets::interface& relay_iface() const {
        return (xos::network::sockets::interface&)relay_os_iface();
    }

    /// ...addr /  ...addrlen
    virtual xos::network::sockets::sockaddr_t& accept_addr() const {
        return (xos::network::sockets::sockaddr_t&)accept_addr_;
    }
    virtual xos::network::sockets::socklen_t& accept_addrlen() const {
        return (xos::network::sockets::socklen_t&)accept_addrlen_;
    }
    virtual xos::network::sockets::sockaddr_t& connect_addr() const {
        return (xos::network::sockets::sockaddr_t&)connect_addr_;
    }
    virtual xos::network::sockets::socklen_t& connect_addrlen() const {
        return (xos::network::sockets::socklen_t&)connect_addrlen_;
    }
    virtual xos::network::sockets::sockaddr_t& relay_addr() const {
        return (xos::network::sockets::sockaddr_t&)relay_addr_;
    }
    virtual xos::network::sockets::socklen_t& relay_addrlen() const {
        return (xos::network::sockets::socklen_t&)relay_addrlen_;
    }

    /// ...ep
    xos::network::sockets::endpoint& (derives::*ep_)() const;
    virtual xos::network::sockets::endpoint& ep() const {
        if ((this->ep_)) {
            return (this->*ep_)();
        }
        return this->default_ep();
    }
    virtual xos::network::sockets::endpoint& default_ep() const {
        return this->ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& ip_v4_ep() const {
        return (xos::network::sockets::endpoint&)ip_v4_ep_;
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& ip_v6_ep() const {
        return (xos::network::sockets::endpoint&)ip_v6_ep_;
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...tp
    xos::network::sockets::transport& (derives::*tp_)() const;
    virtual xos::network::sockets::transport& tp() const {
        if ((this->tp_)) {
            return (this->*tp_)();
        }
        return this->default_tp();
    }
    virtual xos::network::sockets::transport& default_tp() const {
        return this->ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& ip_v4_tcp_tp() const {
        return (xos::network::sockets::transport&)ip_v4_tcp_tp_;
    }
    virtual xos::network::sockets::transport& ip_v4_udp_tp() const {
        return (xos::network::sockets::transport&)ip_v4_udp_tp_;
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& ip_v6_tcp_tp() const {
        return (xos::network::sockets::transport&)ip_v6_tcp_tp_;
    }
    virtual xos::network::sockets::transport& ip_v6_udp_tp() const {
        return (xos::network::sockets::transport&)ip_v6_udp_tp_;
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    /// ...
    /// ...iface / ...addr / ...ep/ ...tp
    /// 

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...message_chars
    virtual char_t& message_chars(size_t& size) const {
        char_t& message_chars = (char_t&)(*message_chars_);
        size = sizeof(message_chars_);
        return message_chars;
    }
    
    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

protected:
    xos::network::sockets::os::interface accept_os_iface_, connect_os_iface_, relay_os_iface_;
 
    xos::network::sockets::interface accept_iface_, connect_iface_, relay_iface_;

    xos::network::sockets::sockaddr_t accept_addr_, connect_addr_, relay_addr_;
    xos::network::sockets::socklen_t accept_addrlen_, connect_addrlen_, relay_addrlen_;

    xos::network::sockets::ip::v4::endpoint ip_v4_ep_;
    xos::network::sockets::ip::v4::tcp::transport ip_v4_tcp_tp_;
    xos::network::sockets::ip::v4::udp::transport ip_v4_udp_tp_;

#if !defined(WINSOCK_1)
    xos::network::sockets::ip::v6::endpoint ip_v6_ep_;
    xos::network::sockets::ip::v6::tcp::transport ip_v6_tcp_tp_;
    xos::network::sockets::ip::v6::udp::transport ip_v6_udp_tp_;
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    
    char_t message_chars_[4096];
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace sockets 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HPP
