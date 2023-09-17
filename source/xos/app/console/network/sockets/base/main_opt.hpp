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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 9/7/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPT_HPP

#include "xos/app/console/network/base/main.hpp"

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST "*"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT 8080

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST "localhost"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT 80

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_HOST XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_PORT XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_ACCEPT_HOST_OPTARG "[{ * | name | ddd.ddd.ddd.ddd | ...}[:{ 0..2^16-1 }]]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_CONNECT_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}[:{ 0..2^16-1 }]]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_RELAY_HOST_OPTARG \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_CONNECT_HOST_OPTARG

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPT "accept-one"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTARG XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_ACCEPT_HOST_OPTARG
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTUSE "accept one connection"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTVAL_S "1::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTVAL_C '1'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPT "accept"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTARG XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_ACCEPT_HOST_OPTARG
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTUSE "accept connections"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTVAL_S "a::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTVAL_C 'a'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPT "connect"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTARG XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_CONNECT_HOST_OPTARG
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTUSE "connect"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTVAL_S "c::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTVAL_C 'c'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPT "send"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTARG XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_CONNECT_HOST_OPTARG
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTUSE "send message"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTVAL_S "s::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTVAL_C 's'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPT "receive"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTARG XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_ACCEPT_HOST_OPTARG
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTUSE "receive messages"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTVAL_S "r::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPT "host"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTUSE "Hostname or address"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S "o::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C 'o'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPT "port"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG "[{ 0..2^16-1 }]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTUSE "Port number"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S "p::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPT "relay-host"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTUSE "Relay hostname or address"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_S "O::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C 'O'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPT "relay-port"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTUSE "Relay port number"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_S "P::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C 'P'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTION \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::network::base::maint<>,  class TImplements = typename TExtends::implements>

class main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt()
    : run_(0), 
      accept_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST), 
      connect_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST),
      relay_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_HOST),
      accept_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT), 
      connect_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT),
      relay_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_PORT) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
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
    int (derives::*sockets_run_)(int argc, char_t** argv, char_t** env);
    virtual int sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (sockets_run_) {
            if (!(err = (this->*sockets_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_sockets_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_sockets_run(argc, argv, env))) {
            int err2 = 0;
            err = sockets_run(argc, argv, env);
            if ((err2 = after_sockets_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_sockets_run;
        return err;
    }
    virtual int sockets_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int sockets_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...accept_one_run
    int (derives::*accept_one_run_)(int argc, char_t** argv, char_t** env);
    virtual int accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (accept_one_run_) {
            if (!(err = (this->*accept_one_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_accept_one_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool accepted_one = this->accept_one();
        this->set_accept_one();
        if (!(err = all_accept_run(argc, argv, env))) {
        } else {
        }
        this->set_accept_one(accepted_one);
        return err;
    }
    virtual int before_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_accept_one_run(argc, argv, env))) {
            int err2 = 0;
            err = accept_one_run(argc, argv, env);
            if ((err2 = after_accept_one_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_set(argc, argv, env))) {
                sockets_run_ = &derives::all_accept_one_run;
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int accept_one_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        sockets_run_ = 0;
        if (!(err = unset_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_unset(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int accept_one_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...accept_run
    int (derives::*accept_run_)(int argc, char_t** argv, char_t** env);
    virtual int accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (accept_run_) {
            if (!(err = (this->*accept_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_accept_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool accept_restart = false;
        do {
            LOGGER_IS_LOGGED_INFO("this->set_accept_done(false)...");
            this->set_accept_done(false);

            LOGGER_IS_LOGGED_INFO("!(err = all_accept(argc, argv, env))...");
            if (!(err = all_accept(argc, argv, env))) {

                LOGGER_IS_LOGGED_INFO("!(this->accept_one())...");
                if (!(this->accept_one())) {
                    LOGGER_IS_LOGGED_INFO("accept_restart = this->accept_restart()...");
                    accept_restart = this->accept_restart();
                } else {
                    LOGGER_IS_LOGGED_INFO("...(this->accept_one())");
                }
                LOGGER_IS_LOGGED_INFO("this->set_accept_restart(false)...");
                this->set_accept_restart(false);
            } else {
                LOGGER_IS_LOGGED_ERROR("...(" << err << " = all_accept(argc, argv, env))");
            }
        } while (accept_restart);
        return err;
    }
    virtual int before_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_accept_run(argc, argv, env))) {
            int err2 = 0;
            err = accept_run(argc, argv, env);
            if ((err2 = after_accept_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_set(argc, argv, env))) {
                sockets_run_ = &derives::all_accept_run;
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int accept_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        sockets_run_ = 0;
        if (!(err = unset_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_unset(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int accept_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...connect_run
    int (derives::*connect_run_)(int argc, char_t** argv, char_t** env);
    virtual int connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (connect_run_) {
            if (!(err = (this->*connect_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_connect_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_connect(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_connect_run(argc, argv, env))) {
            int err2 = 0;
            err = connect_run(argc, argv, env);
            if ((err2 = after_connect_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_set(argc, argv, env))) {
                sockets_run_ = &derives::all_connect_run;
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int connect_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        sockets_run_ = 0;
        if (!(err = unset_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_unset(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int connect_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...send_run
    int (derives::*send_run_)(int argc, char_t** argv, char_t** env);
    virtual int send_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (send_run_) {
            if (!(err = (this->*send_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_send_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_send_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_send(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_send_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_run(argc, argv, env))) {
            int err2 = 0;
            err = send_run(argc, argv, env);
            if ((err2 = after_send_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_send_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_set(argc, argv, env))) {
                sockets_run_ = &derives::all_send_run;
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int send_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_send_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        sockets_run_ = 0;
        if (!(err = unset_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_unset(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int send_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...receive_run
    int (derives::*receive_run_)(int argc, char_t** argv, char_t** env);
    virtual int receive_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (receive_run_) {
            if (!(err = (this->*receive_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_receive_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_receive_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool accept_restart = false;
        do {
            LOGGER_IS_LOGGED_INFO("this->set_accept_done(false)...");
            this->set_accept_done(false);

            LOGGER_IS_LOGGED_INFO("!(err = all_accept(argc, argv, env))...");
            if (!(err = all_receive(argc, argv, env))) {

                LOGGER_IS_LOGGED_INFO("!(this->accept_one())...");
                if (!(this->accept_one())) {
                    LOGGER_IS_LOGGED_INFO("accept_restart = this->accept_restart()...");
                    accept_restart = this->accept_restart();
                } else {
                    LOGGER_IS_LOGGED_INFO("...(this->accept_one())");
                }
                LOGGER_IS_LOGGED_INFO("this->set_accept_restart(false)...");
                this->set_accept_restart(false);
            } else {
                LOGGER_IS_LOGGED_ERROR("...(" << err << " = all_accept(argc, argv, env))");
            }
        } while (accept_restart);
        return err;
    }
    virtual int before_receive_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_run(argc, argv, env))) {
            int err2 = 0;
            err = receive_run(argc, argv, env);
            if ((err2 = after_receive_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_receive_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_set(argc, argv, env))) {
                sockets_run_ = &derives::all_receive_run;
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int receive_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_receive_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        sockets_run_ = 0;
        if (!(err = unset_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_unset(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int receive_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int receive_one_receive_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool accepted_one = this->accept_one();
        this->set_accept_one();
        if (!(err = default_receive_run(argc, argv, env))) {
        } else {
        }
        this->set_accept_one(accepted_one);
        return err;
    }
    virtual int set_receive_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_set(argc, argv, env))) {
                receive_run_ = &derives::receive_one_receive_run;
                sockets_run_ = &derives::all_receive_run;
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int receive_one_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_receive_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        receive_run_ = 0;
        sockets_run_ = 0;
        if (!(err = unset_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_unset(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int receive_one_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// ...output_host_run
    int (derives::*output_host_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_host_run_) {
            if (!(err = (this->*output_host_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_host_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& host = this->host();
        const char_t* chars = 0; size_t length = 0;
        if ((chars = host.has_chars(length))) {
            this->outln(chars, length);
        } else {
            this->outln();
        }
        return err;
    }
    virtual int before_output_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_host_run(argc, argv, env))) {
            int err2 = 0;
            err = output_host_run(argc, argv, env);
            if ((err2 = after_output_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_host_run;
        return err;
    }
    virtual int output_host_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_host_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...output_port_run
    int (derives::*output_port_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_port_run_) {
            if (!(err = (this->*output_port_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_port_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const short& port = this->port();
        if ((0 < (port))) {
            unsigned_to_string string(port);
            const char_t* chars = 0; size_t length = 0;
            if ((chars = string.has_chars(length))) {
                this->outln(chars, length);
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int before_output_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_port_run(argc, argv, env))) {
            int err2 = 0;
            err = output_port_run(argc, argv, env);
            if ((err2 = after_output_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_port_run;
        return err;
    }
    virtual int output_port_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_port_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...output_relay_host_run
    int (derives::*output_relay_host_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_relay_host_run_) {
            if (!(err = (this->*output_relay_host_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_relay_host_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& host = this->relay_host();
        const char_t* chars = 0; size_t length = 0;
        if ((chars = host.has_chars(length))) {
            this->outln(chars, length);
        } else {
            this->outln();
        }
        return err;
    }
    virtual int before_output_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_relay_host_run(argc, argv, env))) {
            int err2 = 0;
            err = output_relay_host_run(argc, argv, env);
            if ((err2 = after_output_relay_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_relay_host_run;
        return err;
    }
    virtual int output_relay_host_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_relay_host_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...output_relay_port_run
    int (derives::*output_relay_port_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_relay_port_run_) {
            if (!(err = (this->*output_relay_port_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_relay_port_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const short& port = this->relay_port();
        if ((0 < (port))) {
            unsigned_to_string string(port);
            const char_t* chars = 0; size_t length = 0;
            if ((chars = string.has_chars(length))) {
                this->outln(chars, length);
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int before_output_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_relay_port_run(argc, argv, env))) {
            int err2 = 0;
            err = output_relay_port_run(argc, argv, env);
            if ((err2 = after_output_relay_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_relay_port_run;
        return err;
    }
    virtual int output_relay_port_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_relay_port_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    ///
    /// ...accept
    /// ...
    /// ...accept(int argc, ...)
    virtual int accept(int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_accept(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_accept(argc, argv, env))) {
            int err2 = 0;
            err = accept(argc, argv, env);
            if ((err2 = after_accept(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...accept
    /// 

    ///
    /// ...connect
    /// ...
    /// ...connect(int argc, ...)
    virtual int connect(int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_connect(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_connect(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_connect(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_connect(argc, argv, env))) {
            int err2 = 0;
            err = connect(argc, argv, env);
            if ((err2 = after_connect(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...connect
    /// 

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    ///
    /// ...send
    /// ...
    /// ...send(int argc, ...)
    virtual int send(int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_send(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_send(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_send(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_send(argc, argv, env))) {
            int err2 = 0;
            err = send(argc, argv, env);
            if ((err2 = after_send(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...send
    /// 

    ///
    /// ...receive
    /// ...
    /// ...receive(int argc, ...)
    virtual int receive(int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int before_receive(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_receive(argc, argv, env))) {
            int err2 = 0;
            err = receive(argc, argv, env);
            if ((err2 = after_receive(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...receive
    /// 

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// on...accept_one_option...
    virtual int on_get_accept_one_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_accept_one_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_receive_one_run(argc, argv, env))) {
            if (!(err = receive_one_run_set(argc, argv, env))) {
                if (!(err = set_accept_one_run(argc, argv, env))) {
                    if (!(err = accept_one_run_set(argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_accept_one_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_accept_one_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_accept_one_run(argc, argv, env))) {
            if (!(err = accept_one_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_accept_one_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_accept_one_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_accept_one_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_accept_one_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_accept_one_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* accept_one_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTARG;
        return chars;
    }

    /// on...accept_option...
    virtual int on_get_accept_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_accept_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_accept_run(argc, argv, env))) {
            if (!(err = accept_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_accept_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_accept_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_accept_run(argc, argv, env))) {
            if (!(err = accept_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_accept_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_accept_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_accept_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_accept_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_accept_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* accept_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTARG;
        return chars;
    }

    /// on...connect_option...
    virtual int on_get_connect_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_connect_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_connect_run(argc, argv, env))) {
            if (!(err = connect_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_connect_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_connect_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_connect_run(argc, argv, env))) {
            if (!(err = connect_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_connect_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_connect_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_connect_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_connect_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_connect_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* connect_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTARG;
        return chars;
    }

    /// on...send_option...
    virtual int on_get_send_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_send_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_send_run(argc, argv, env))) {
            if (!(err = send_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_send_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_send_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_send_run(argc, argv, env))) {
            if (!(err = send_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_send_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_send_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_send_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_send_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_send_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* send_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_SEND_OPTARG;
        return chars;
    }

    /// on...receive_option...
    virtual int on_get_receive_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_receive_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_receive_run(argc, argv, env))) {
            if (!(err = receive_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_receive_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_receive_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_receive_run(argc, argv, env))) {
            if (!(err = receive_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_receive_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_receive_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_receive_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_receive_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_receive_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* receive_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RECEIVE_OPTARG;
        return chars;
    }

    /// on...host_option...
    virtual int on_get_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_host_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_host_run(argc, argv, env))) {
            if (!(err = output_host_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_host(optarg);
        } else {
        }
        return err;
    }
    virtual int on_host_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_host_option_get(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_host_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_host_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG;
        return chars;
    }

    /// on...port_option...
    virtual int on_get_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_port_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_port_run(argc, argv, env))) {
            if (!(err = output_port_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            unsigned port = arg.to_unsigned();
            if ((0 < port)) {
                this->set_port(port);
            }
        } else {
        }
        return err;
    }
    virtual int on_port_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_port_option_get(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_port_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_port_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG;
        return chars;
    }

    /// on...relay_host_option...
    virtual int on_get_relay_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_relay_host_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_relay_host_run(argc, argv, env))) {
            if (!(err = output_relay_host_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_relay_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_relay_host(optarg);
        } else {
        }
        return err;
    }
    virtual int on_relay_host_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_relay_host_option_get(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_relay_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_relay_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_relay_host_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_relay_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_relay_host_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* relay_host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG;
        return chars;
    }

    /// on...relay_port_option...
    virtual int on_get_relay_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_relay_port_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_relay_port_run(argc, argv, env))) {
            if (!(err = output_relay_port_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_relay_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            unsigned relay_port = arg.to_unsigned();
            if ((0 < relay_port)) {
                this->set_relay_port(relay_port);
            }
        } else {
        }
        return err;
    }
    virtual int on_relay_port_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_relay_port_option_get(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_relay_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_relay_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_relay_port_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_relay_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_relay_port_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* relay_port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG;
        return chars;
    }

    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTVAL_C:
            err = this->on_accept_one_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTVAL_C:
            err = this->on_accept_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTVAL_C:
            err = this->on_connect_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            err = this->on_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            err = this->on_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C:
            err = this->on_relay_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C:
            err = this->on_relay_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_ONE_OPTVAL_C:
            chars = this->accept_one_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ACCEPT_OPTVAL_C:
            chars = this->accept_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CONNECT_OPTVAL_C:
            chars = this->connect_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            chars = this->host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            chars = this->port_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C:
            chars = this->relay_host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C:
            chars = this->relay_port_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTVAL_C:
            chars = this->send_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTVAL_C:
            chars = this->receive_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTVAL_C:
            chars = this->message_sent_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTVAL_C:
            chars = this->message_received_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///
    /// ..host / ..port
    /// ...
    /// host / port
    virtual string_t& set_host(const string_t& to) {
        this->set_accept_host(to);
        this->set_connect_host(to);
        return this->host();
    }
    virtual string_t& set_host(const char_t* to) {
        this->set_accept_host(to);
        this->set_connect_host(to);
        return this->host();
    }
    virtual string_t& host() const {
        return this->connect_host();
    }
    virtual short& set_port(short to) {
        this->set_accept_port(to);
        this->set_connect_port(to);
        return this->port();
    }
    virtual short& port() const {
        return this->connect_port();
    }

    /// ...accept_host / ...accept_port
    virtual string_t& set_accept_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_accept_host(chars);
    }
    virtual string_t& set_accept_host(const char_t* to) {
        string_t& accept_host = this->accept_host();
        if ((to)) accept_host.assign(to);
        else accept_host.clear();
        return accept_host;
    }
    virtual const string_t& get_accept_host() const {
        return this->accept_host();
    }
    virtual string_t& accept_host() const {
        return (string_t&)accept_host_;
    }
    virtual short& set_accept_port(short to) {
        short& accept_port = this->accept_port();
        accept_port = to;
        return accept_port;
    }
    virtual const short& get_accept_port() const {
        return this->accept_port();
    }
    virtual short& accept_port() const {
        return (short&)accept_port_;
    }

    /// ...connect_host / ...connect_port
    virtual string_t& set_connect_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_connect_host(chars);
    }
    virtual string_t& set_connect_host(const char_t* to) {
        string_t& connect_host = this->connect_host();
        if ((to)) connect_host.assign(to);
        else connect_host.clear();
        return connect_host;
    }
    virtual const string_t& get_connect_host() const {
        return this->connect_host();
    }
    virtual string_t& connect_host() const {
        return (string_t&)connect_host_;
    }
    virtual short& set_connect_port(short to) {
        short& connect_port = this->connect_port();
        connect_port = to;
        return connect_port;
    }
    virtual const short& get_connect_port() const {
        return this->connect_port();
    }
    virtual short& connect_port() const {
        return (short&)connect_port_;
    }

    /// ...relay_host / ...relay_port
    virtual string_t& set_relay_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_relay_host(chars);
    }
    virtual string_t& set_relay_host(const char_t* to) {
        string_t& relay_host = this->relay_host();
        if ((to)) relay_host.assign(to);
        else relay_host.clear();
        return relay_host;
    }
    virtual string_t& relay_host() const {
        return (string_t&)relay_host_;
    }
    virtual short& set_relay_port(short to) {
        short& relay_port = this->relay_port();
        relay_port = to;
        return relay_port;
    }
    virtual short& relay_port() const {
        return (short&)relay_port_;
    }
    /// ...
    /// ..host / ..port
    /// 

protected:
    string_t accept_host_, connect_host_, relay_host_;
    short accept_port_, connect_port_, relay_port_;
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace sockets 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPT_HPP
