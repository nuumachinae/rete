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
///   File: interface.hpp
///
/// Author: $author$
///   Date: 9/8/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_SOCKETS_POSIX_INTERFACE_HPP
#define XOS_NETWORK_SOCKETS_POSIX_INTERFACE_HPP

#include "xos/network/sockets/interface.hpp"
#include <sys/socket.h>
#include <netinet/tcp.h>

namespace xos {
namespace network {
namespace sockets {
namespace posix {

/// enum DELAY_OPT
enum {
    DELAY_OPT_OFF = 1, /// Note opposite of Windows
    DELAY_OPT_ON  = 0  /// Note opposite of Windows
}; /// enum DELAY_OPT

typedef int socket_attached_t;
typedef int socket_unattached_t;
enum { socket_unattached = 0 };

namespace extended {
/// class interfacet
template 
<class TExtends = sockets::extended::interfacet
 <socket_attached_t, socket_unattached_t, socket_unattached>, 
 class TImplements = typename TExtends::implements>

class exported interfacet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef interfacet derives;

    typedef typename extends::attached_t attached_t;
    typedef typename extends::unattached_t unattached_t;
    enum { unattached = extends::unattached };

    /// constructor / destructor
    interfacet(const interfacet& copy): extends(copy) {
    }
    interfacet() {
    }
    virtual ~interfacet() {
    }
    
    /// bind
    using implements::bind;
    virtual bool bind(const sockaddr_t* addr, socklen_t addrlen) {
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->attached_to())) {
            if ((this->bind_as_reuseaddr())) {
                this->set_reuseaddr_opt();
            }
            if ((bind_detached(detached, addr, addrlen))) {
                return true;
            }
        }
        return false; 
    }

    /// ...reuseaddr
    virtual bool set_reuseaddr_opt(bool on = true) {
        int value = (on)?(1):(0);
        LOGGER_IS_LOGGED_DEBUG("set_opt(SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value))...");
        if ((this->set_opt(SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool set_noreuseaddr_opt(bool on = true) {
        int value = (on)?(0):(1);
        LOGGER_IS_LOGGED_DEBUG("set_opt(SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value))...");
        if ((this->set_opt(SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool get_reuseaddr_opt(bool &on) const {
        int value = 0;
        socklen_t length = sizeof(value);
        LOGGER_IS_LOGGED_DEBUG("get_opt(SOL_SOCKET, SO_REUSEADDR, &value, length)...");
        if ((this->get_opt(SOL_SOCKET, SO_REUSEADDR, &value, length))) {
            on = (value != 0);
            return true;
        }
        return false;
    }

    /// ...delay
    virtual bool set_delay_opt(bool on = true) {
        int value = (on)?(DELAY_OPT_ON):(DELAY_OPT_OFF); /// Note opposite of Windows
        LOGGER_IS_LOGGED_DEBUG("set_opt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value))...");
        if ((this->set_opt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool set_nodelay_opt(bool on = true) {
        int value = (on)?(DELAY_OPT_OFF):(DELAY_OPT_ON); /// Note opposite of Windows
        LOGGER_IS_LOGGED_DEBUG("set_opt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value))...");
        if ((this->set_opt(IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool get_delay_opt(bool &on) const {
        int value = 0;
        socklen_t length = sizeof(value);
        LOGGER_IS_LOGGED_DEBUG("get_opt(IPPROTO_TCP, TCP_NODELAY, &value, length))...");
        if ((this->get_opt(IPPROTO_TCP, TCP_NODELAY, &value, length))) {
            on = (value == 0);
            return true;
        }
        return false;
    }

    /// ...linger
    virtual bool set_linger_opt
    (bool on = true, linger_seconds_t linger_seconds = -1) {
        struct linger value;
        value.l_onoff = (on)?(1):(0);
        value.l_linger = (0>linger_seconds)?(this->default_linger_seconds()):(linger_seconds);
        LOGGER_IS_LOGGED_DEBUG("set_opt(SOL_SOCKET, SO_LINGER, &value, sizeof(value))...");
        if ((this->set_opt(SOL_SOCKET, SO_LINGER, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool set_dont_linger_opt
    (bool on = true, linger_seconds_t linger_seconds = -1) {
        struct linger value;
        value.l_onoff = (on)?(0):(1);
        value.l_linger = (0>linger_seconds)?(this->default_linger_seconds()):(linger_seconds);
        LOGGER_IS_LOGGED_DEBUG("set_opt(SOL_SOCKET, SO_LINGER, &value, sizeof(value))...");
        if ((this->set_opt(SOL_SOCKET, SO_LINGER, &value, sizeof(value)))) {
            return true;
        }
        return false;
    }
    virtual bool get_linger_opt(bool &on, linger_seconds_t &linger_seconds) const {
        struct linger value = {0, 0};
        socklen_t length = sizeof(value);
        LOGGER_IS_LOGGED_DEBUG("get_opt(SOL_SOCKET, SO_LINGER, &value, length)...");
        if ((this->get_opt(SOL_SOCKET, SO_LINGER, &value, length))) {
            on = (value.l_onoff == 0);
            linger_seconds = (value.l_linger);
            return true;
        }
        return false;
    }

    /// open / close / shutdown detached
    virtual attached_t open_detached(domain_t domain, type_t type, protocol_t protocol) const {
        attached_t detached = ((attached_t)unattached);
        LOGGER_IS_LOGGED_DEBUG("::socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")...");
        if (0 <= (detached = ::socket(domain, type, protocol))) {
            LOGGER_IS_LOGGED_DEBUG("..." << detached << " = ::socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
        } else {
            LOGGER_IS_LOGGED_ERROR("failed errno = " << errno << " on ::socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
        }
        return detached;
    }
    virtual bool close_detached(attached_t detached) const {
        if (((attached_t)unattached) != (detached)) {
            int err = 0;
            LOGGER_IS_LOGGED_DEBUG("::close(" << detached << ")...");
            if (!(err = ::close(detached))) {
                LOGGER_IS_LOGGED_DEBUG("...::close(" << detached << ")");
                return true;
            } else {
                LOGGER_IS_LOGGED_ERROR("failed errno = " << errno << " on ::close(" << detached << ")");
            }
        }
        return false;
    }
    virtual bool shutdown_detached(attached_t detached, shutdown_how_t how) const {
        if (((attached_t)unattached) != (detached)) {
            int sd_how = ((how == shutdown_read)?(SHUT_RD)
                          :((how == shutdown_write)?(SHUT_WR)
                          :((how == shutdown_both)?(SHUT_RDWR):(0))));
            int err = 0;
            LOGGER_IS_LOGGED_DEBUG("::shutdown(detached, sd_how)...");
            if (!(err = ::shutdown(detached, sd_how))) {
                LOGGER_IS_LOGGED_DEBUG("...::shutdown(detached, sd_how)");
                return true;
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed " << errno << " on shutdown(detached, sd_how)");
            }
        }
        return false;
    }

    /// connect / bind / accept / listen detached
    virtual bool connect_detached
    (attached_t detached, const sockaddr_t* addr, socklen_t addrlen) const {
        if (((attached_t)unattached) != (detached)) {
            int err = 0;
            LOGGER_IS_LOGGED_DEBUG("::connect(..., addrlen = " << addrlen << ")...");
            if (!(err = ::connect(detached, addr, addrlen))) {
                LOGGER_IS_LOGGED_DEBUG("...::connect(..., addrlen = " << addrlen << ")...");
                return true;
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::connect(..., addrlen = " << addrlen << ")");
            }
        }
        return false;
    }
    virtual bool bind_detached
    (attached_t detached, const sockaddr_t* addr, socklen_t addrlen) const {
        if (((attached_t)unattached) != (detached)) {
            int err = 0;
            LOGGER_IS_LOGGED_DEBUG("::bind(..., addrlen = " << addrlen << ")...");
            if (!(err = ::bind(detached, addr, addrlen))) {
                LOGGER_IS_LOGGED_DEBUG("...::bind(..., addrlen = " << addrlen << ")...");
                return true;
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::bind(..., addrlen = " << addrlen << ")");
            }
        }
        return false; 
    }
    virtual bool accept_detached
    (attached_t detached, implemented::interface& sock, sockaddr_t* addr, socklen_t& addrlen) const {
        if (((attached_t)unattached) != (detached)) {
            int err = 0;
            attached_t accepted = ((attached_t)unattached);
            LOGGER_IS_LOGGED_DEBUG("::accept(..., addrlen = " << addrlen << ")...");
            if (0 <= (accepted = ::accept(detached, addr, &addrlen))) {
                LOGGER_IS_LOGGED_DEBUG("...::accept(..., addrlen = " << addrlen << ")...");
                if ((accepted_detached(accepted, sock, addr, addrlen))) {
                    return true;
                }
                LOGGER_IS_LOGGED_DEBUG("::close(accepted = " << accepted << ")...");
                if ((err = ::close(accepted))) {
                    LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::aclose(accepted = " << accepted << ")");
                }
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::accept(..., addrlen = " << addrlen << ")");
            }
        }
        return false; 
    }
    virtual bool accepted_detached
    (attached_t detached, implemented::interface& sock, sockaddr_t* addr, socklen_t& addrlen) const {
        if (((attached_t)unattached) != (detached)) {
        }
        return false; 
    }
    virtual bool listen_detached(attached_t detached, backlog_t backlog) const { 
        if (((attached_t)unattached) != (detached)) {
            int err = 0;
            LOGGER_IS_LOGGED_DEBUG("::listen(..., backlog = " << backlog << ")...");
            if (!(err = ::listen(detached, backlog))) {
                LOGGER_IS_LOGGED_DEBUG("...::listen(..., backlog = " << backlog << ")...");
                return true;
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::listen(..., backlog = " << backlog << ")");
            }
        }
        return false; 
    }

    /// send..._detached / recv..._detached
    virtual ssize_t send_detached
    (attached_t detached, const void* buf, size_t len, send_flags_t flags) const {
        if (((attached_t)unattached) != (detached)) {
            const char* chars = ((buf) && (128 >= len))?((const char*)buf):("...");
            ssize_t count = 0;
            LOGGER_IS_LOGGED_DEBUG("::send(..., buf = \"" << chars << "\", len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::send(detached, buf, len, flags))) {
                LOGGER_IS_LOGGED_DEBUG("..." << count << " = ::send(..., buf = \"" << chars << "\", len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::send(..., buf = \"" << chars << "\", len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }
    virtual ssize_t recv_detached
    (attached_t detached, void* buf, size_t len, recv_flags_t flags) const {
        if (((attached_t)unattached) != (detached)) {
            ssize_t count = 0;
            LOGGER_IS_LOGGED_DEBUG("::recv(..., len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::recv(detached, buf, len, flags))) {
                LOGGER_IS_LOGGED_DEBUG("..." << count << " = ::recv(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::recv(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }
    virtual ssize_t sendto_detached
    (attached_t detached, const void* buf, size_t len, send_flags_t flags,
     const sockaddr_t* addr, socklen_t addrlen) {
        if ((((attached_t)unattached) != (detached)) 
            && (buf) && (len) && (addr) && (addrlen)) {
            ssize_t count = 0;
            LOGGER_IS_LOGGED_DEBUG("::sendto(..., len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::sendto(detached, buf, len, flags, addr, addrlen))) {
                LOGGER_IS_LOGGED_DEBUG("..." << count << " = ::sendto(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::sendto(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }
    virtual ssize_t recvfrom_detached
    (attached_t detached, void* buf, size_t len, recv_flags_t flags,
     sockaddr_t* addr, socklen_t* addrlen) {
        if ((((attached_t)unattached) != (detached)) 
            && (buf) && (len) && (addr) && (addrlen)) {
            ssize_t count = 0;
            LOGGER_IS_LOGGED_DEBUG("::recvfrom(..., len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::recvfrom(detached, buf, len, flags, addr, addrlen))) {
                LOGGER_IS_LOGGED_DEBUG("..." << count << " = ::recvfrom(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::recvfrom(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return -1;
    }

    /// ...opt_detached
    virtual bool set_opt_detached
    (attached_t detached, opt_level_t level, opt_name_t name, const void* value, socklen_t length) {
        if ((((attached_t)unattached) != (detached)) && (value) && (0 < length)) {
            int err = 0;
            LOGGER_IS_LOGGED_DEBUG("::setsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
            if (!(err = ::setsockopt(detached, level, name, (const char*)value, length))) {
                LOGGER_IS_LOGGED_DEBUG("...setsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
                return true;
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::setsockopt(..., level = " << level << ", name = " << name << ", ..., length)");
            }
        }
        return false;
    }
    virtual bool get_opt_detached
    (attached_t detached, opt_level_t level, opt_name_t name, void* value, socklen_t &length) const {
        if ((((attached_t)unattached) != (detached)) && (value)) {
            int err = 0;
            LOGGER_IS_LOGGED_DEBUG("::getsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
            if (!(err = ::getsockopt(detached, level, name, (char*)value, &length))) {
                LOGGER_IS_LOGGED_DEBUG("...::getsockopt(..., level = " << level << ", name = " << name << ", ..., length)...");
                return true;
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed errno = " << errno << " on ::getsockopt(..., level = " << level << ", name = " << name << ", ..., length)");
            }
        }
        return false;
    }

}; /// class interfacet
typedef interfacet<> interface;
} /// namespace extended

} /// namespace posix

namespace implemented {
/// class interface
class exported interface: virtual public posix::extended::interface::implements, public posix::extended::interface {
public:
    typedef posix::extended::interface::implements implements;
    typedef posix::extended::interface extends;
    typedef interface derives;

    /// constructor / destructor
    interface(const interface& copy): extends(copy) {
    }
    interface() {
    }
    virtual ~interface() {
    }

    /// accepted_detached
    virtual bool accepted_detached
    (attached_t detached, implemented::interface& sock, sockaddr_t* addr, socklen_t& addrlen) const {
        if ((sock.closed())) {
            if (((attached_t)unattached) != (detached)) {
                sock.attach_opened(detached);
                return true;
            }
        }
        return false; 
    }

    /// implemented
    virtual implemented::interface* implemented() const {
        return (implemented::interface*)this;
    }
}; /// class interface
} /// namespace implemented

namespace posix {

/// class interface
class exported interface: virtual public implemented::interface::implements, public implemented::interface {
public:
    typedef implemented::interface::implements implements;
    typedef implemented::interface extends;
    typedef interface derives;

    /// constructor / destructor
    interface(const interface& copy): extends(copy) {
    }
    interface() {
    }
    virtual ~interface() {
    }
}; /// class interface

} /// namespace posix 
} /// namespace sockets 
} /// namespace network 
} /// namespace xos 

#endif /// ndef XOS_NETWORK_SOCKETS_POSIX_INTERFACE_HPP
