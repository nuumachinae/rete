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
///   Date: 9/7/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_SOCKETS_INTERFACE_HPP
#define XOS_NETWORK_SOCKETS_INTERFACE_HPP

#include "xos/network/interface.hpp"
#include "xos/network/sockets/address.hpp"
#include "xos/network/sockets/transport.hpp"
#include "xos/network/sockets/endpoint.hpp"

namespace xos {
namespace network {
namespace sockets {

/// enum backlog_t
typedef int backlog_t;
enum {
    backlog_none = 0,
    backlog_default = SOMAXCONN
}; /// enum backlog_t

/// enum send_flags_t
typedef int send_flags_t;
enum {
    send_flags_default = 0
}; /// enum send_flags_t

typedef int recv_flags_t;
enum {
    recv_flags_default = 0
};

typedef int opt_level_t;
typedef int opt_name_t;

typedef int linger_seconds_t;
enum {
    linger_seconds_none = 0,
    linger_seconds_default = 10
};

typedef bool bind_as_reuseaddr_t;
enum {
    bind_as_reuseaddr_default = true
};

typedef int shutdown_how_t;
enum {
    shutdown_none = 0,
    shutdown_read = 1,
    shutdown_write = 2,
    shutdown_both = (shutdown_read | shutdown_write)
};

typedef address_family_t domain_t;
typedef transport_type_t type_t;
typedef transport_protocol_t protocol_t;

namespace implemented {
class exported interface;
} /// namespace implemented

/// class interfacet
template <class TImplements = network::interface>
class exported interfacet: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef interfacet derives;

    /// open
    virtual bool open(const transport& tp) {
        domain_t domain = tp.domain();
        type_t type = tp.type();
        protocol_t protocol = tp.protocol();
        
        LOGGER_IS_LOGGED_DEBUG("this->open(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")...");
        if ((this->open(domain, type, protocol))) {
            return true;
        } else {
            LOGGER_IS_LOGGED_ERROR("...failed on this->open(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
        }
        return false;
    }

    /// connect / bind / accept / listen
    virtual bool connect(const endpoint& ep) {
        sockaddr_t* addr = 0;
        socklen_t addrlen = 0;
        if ((addr = ep.socket_address(addrlen))) {
            if ((this->connect(addr, addrlen))) {
                return true;
            }
        }
        return false;
    }
    virtual bool bind(const endpoint& ep) {
        sockaddr_t* addr = 0;
        socklen_t addrlen = 0;
        if ((addr = ep.socket_address(addrlen))) {
            if ((this->bind(addr, addrlen))) {
                return true;
            }
        }
        return false;
    }
    virtual bool listen(const endpoint& ep) {
        sockaddr_t* addr = 0;
        socklen_t addrlen = 0;
        if ((addr = ep.socket_address(addrlen))) {
            if ((this->bind(addr, addrlen))) {
                if ((this->listen())) {
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool accept(implemented::interface& sk, const endpoint& ep) {
        sockaddr_t* addr = 0;
        socklen_t addrlen = 0;
        if ((addr = ep.socket_address(addrlen))) {
            if ((this->accept(sk, addr, addrlen))) {
                return true;
            }
        }
        return false; 
    }

    /// send... / recv...
    virtual ssize_t sendto(const void* buf, size_t len, send_flags_t flags, const endpoint& ep) {
        sockaddr_t* addr = 0;
        socklen_t addrlen = 0;
        if ((addr = ep.socket_address(addrlen))) {
            ssize_t count = this->sendto(buf, len, flags, addr, addrlen);
            return count;
        }
        return -1;
    }
    virtual ssize_t recvfrom(void* buf, size_t len, send_flags_t flags, const endpoint& ep) {
        sockaddr_t* addr = 0;
        socklen_t addrlen = 0;
        if ((addr = ep.recv_socket_address(addrlen))) {
            ssize_t count = this->recvfrom(buf, len, flags, addr, &addrlen);
            return count;
        }
        return -1;
    }

    /// open / close / shutdown
    virtual bool open(domain_t domain, type_t type, protocol_t protocol) {
        return false;
    }
    virtual bool close() {
        return false;
    }
    virtual bool shutdown(shutdown_how_t how) {
        return false;
    }
    virtual bool shutdown() {
        shutdown_how_t how = shutdown_both;
        return this->shutdown(how);
    }

    /// connect / bind / accept / listen
    virtual bool connect(const sockaddr_t* addr, socklen_t addrlen) {
        return false; 
    }
    virtual bool bind(const sockaddr_t* addr, socklen_t addrlen) {
        return false; 
    }
    virtual bool accept(implemented::interface& sock, sockaddr_t* addr, socklen_t& addrlen) {
        return false; 
    }
    virtual bool listen(backlog_t backlog) { 
        return false; 
    }
    virtual bool listen() {
        backlog_t backlog = this->default_backlog();
        return this->listen(backlog);
    }

    /// send... / recv...
    virtual ssize_t send(const void* buf, size_t len) {
        return send(buf, len, send_flags_default);
    }
    virtual ssize_t recv(void* buf, size_t len) {
        return recv(buf, len, recv_flags_default);
    }
    virtual ssize_t send(const void* buf, size_t len, send_flags_t flags) {
        return -1;
    }
    virtual ssize_t recv(void* buf, size_t len, recv_flags_t flags) {
        return -1;
    }
    virtual ssize_t sendto
    (const void* buf, size_t len, send_flags_t flags, const sockaddr_t* addr, socklen_t addrlen) {
        return -1;
    }
    virtual ssize_t recvfrom
    (void* buf, size_t len, recv_flags_t flags, sockaddr_t* addr, socklen_t* addrlen) {
        return -1;
    }

    /// reuseaddr
    virtual bool set_reuseaddr_opt(bool on = true) {
        return false;
    }
    virtual bool set_noreuseaddr_opt(bool on = true) {
        return false;
    }
    virtual bool get_reuseaddr_opt(bool &on) const {
        return false;
    }

    /// delay
    virtual bool set_delay_opt(bool on = true) {
        return false;
    }
    virtual bool set_nodelay_opt(bool on = true) {
        return false;
    }
    virtual bool get_delay_opt(bool &on) const {
        return false;
    }

    /// linger
    virtual bool set_linger_opt(bool on = true, linger_seconds_t linger_seconds = -1) {
        return false;
    }
    virtual bool set_dont_linger_opt(bool on = true, linger_seconds_t linger_seconds = -1) {
        return false;
    }
    virtual bool get_linger_opt(bool &on, linger_seconds_t &linger_seconds) const {
        return false;
    }

    /// ...opt
    virtual bool set_opt(opt_level_t level, opt_name_t name, const void* value, socklen_t length) {
        return false;
    }
    virtual bool get_opt(opt_level_t level, opt_name_t name, void* value, socklen_t &length) const {
        return false;
    }

    /// ...backlog / ...linger... / ...reuseaddr
    virtual backlog_t default_backlog() const {
        return backlog_default;
    }
    virtual linger_seconds_t default_linger_seconds() const {
        return linger_seconds_default;
    }
    virtual bool bind_as_reuseaddr() const {
        return default_bind_as_reuseaddr();
    }
    virtual bool default_bind_as_reuseaddr() const {
        return bind_as_reuseaddr_default;
    }

    /// implemented
    virtual implemented::interface* implemented() const {
        return 0;
    }
}; /// class interfacet

namespace implement {
typedef interfacet<> interface;
} /// namespace implement

/// class interface
class exported interface: virtual public sockets::implement::interface {
public:
    typedef sockets::implement::interface implements;
    typedef interface derives;

    /// accept
    using implements::accept;
    virtual bool accept(interface& sock, sockaddr_t* addr, socklen_t& addrlen) {
        implemented::interface* implemented = 0;
        if ((implemented = sock.implemented())) {
            return accept(*implemented, addr, addrlen);
        }
        return false;
    }

    /// sockets_interface
    virtual interface* sockets_interface() const {
        return (interface*)this;
    }
}; /// class interface

namespace extended {
typedef int socket_attached_t;
typedef int socket_unattached_t;
enum { socket_unattached = 0 };

/// class interfacet
template 
<typename TAttachedTo = socket_attached_t, 
 typename TUnattached = socket_unattached_t, TUnattached VUnattached = socket_unattached, 
 class TExtends = network::extended::interfacet<TAttachedTo, TUnattached, VUnattached>, 
 class TImplements = sockets::interface>

class exported interfacet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef interfacet derives;

    typedef TAttachedTo attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    /// constructor / destructor
    interfacet(const interfacet& copy): extends(copy) {
    }
    interfacet() {
    }
    virtual ~interfacet() {
    }

    /// open / close / shutdown
    using implements::open;
    virtual bool open(domain_t domain, type_t type, protocol_t protocol) {
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->open_attached(domain, type, protocol))) {
            this->set_is_open();
            return true;
        }
        return false;
    }
    virtual bool close() {
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->detach())) {
            if ((this->close_detached(detached))) {
                this->set_is_open(false);
                return true;
            }
        }
        return false;
    }
    using implements::shutdown;
    virtual bool shutdown(shutdown_how_t how) {
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->attached_to())) {
            if ((this->shutdown_detached(detached, how))) {
                return true;
            }
        }
        return false;
    }

    /// connect / bind / accept / listen
    using implements::connect;
    virtual bool connect(const sockaddr_t* addr, socklen_t addrlen) {
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->attached_to())) {
            if ((connect_detached(detached, addr, addrlen))) {
                return true;
            }
        }
        return false; 
    }
    using implements::bind;
    virtual bool bind(const sockaddr_t* addr, socklen_t addrlen) {
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->attached_to())) {
            if ((bind_detached(detached, addr, addrlen))) {
                return true;
            }
        }
        return false; 
    }
    using implements::accept;
    virtual bool accept
    (implemented::interface& sock, sockaddr_t* addr, socklen_t& addrlen) {
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->attached_to())) {
            if ((accept_detached(detached, sock, addr, addrlen))) {
                return true;
            }
        }
        return false; 
    }
    using implements::listen;
    virtual bool listen(backlog_t backlog) { 
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->attached_to())) {
            if ((listen_detached(detached, backlog))) {
                return true;
            }
        }
        return false; 
    }

    /// send... / recv...
    virtual ssize_t send(const void* buf, size_t len, send_flags_t flags) {
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->attached_to())) {
            ssize_t count = this->send_detached(detached, buf, len, flags);
            return count;
        }
        return -1;
    }
    virtual ssize_t recv(void* buf, size_t len, recv_flags_t flags) {
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->attached_to())) {
            ssize_t count = this->recv_detached(detached, buf, len, flags);
            return count;
        }
        return -1;
    }
    using implements::sendto;
    virtual ssize_t sendto
    (const void* buf, size_t len, send_flags_t flags,
     const sockaddr_t* addr, socklen_t addrlen) {
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->attached_to())) {
            ssize_t count = this->sendto_detached(detached, buf, len, flags, addr, addrlen);
            return count;
        }
        return -1;
    }
    using implements::recvfrom;
    virtual ssize_t recvfrom
    (void* buf, size_t len, recv_flags_t flags,
     sockaddr_t* addr, socklen_t* addrlen) {
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->attached_to())) {
            ssize_t count = this->recvfrom_detached(detached, buf, len, flags, addr, addrlen);
            return count;
        }
        return -1;
    }

    /// ...opt
    virtual bool set_opt
    (opt_level_t level, opt_name_t name, const void* value, socklen_t length) {
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->attached_to())) {
            return set_opt_detached(detached, level, name, value, length);
        }
        return false;
    }
    virtual bool get_opt
    (opt_level_t level, opt_name_t name, void* value, socklen_t &length) const {
        attached_t detached = ((attached_t)unattached);
        if (((attached_t)unattached) != (detached = this->attached_to())) {
            return get_opt_detached(detached, level, name, value, length);
        }
        return false;
    }

    /// open / close / shutdown detached
    virtual attached_t open_attached(domain_t domain, type_t type, protocol_t protocol) {
        attached_t detached = ((attached_t)unattached);
        if ((this->closed())) {
            if (((attached_t)unattached) != (detached = open_detached(domain, type, protocol))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual attached_t open_detached(domain_t domain, type_t type, protocol_t protocol) const {
        attached_t detached = ((attached_t)unattached);
        return detached;
    }
    virtual bool close_detached(attached_t detached) const {
        if (((attached_t)unattached) != (detached)) {
        }
        return false;
    }
    virtual bool shutdown_detached(attached_t detached, shutdown_how_t how) const {
        if (((attached_t)unattached) != (detached)) {
        }
        return false;
    }

    /// connect / bind / accept / listen detached
    virtual bool connect_detached
    (attached_t detached, const sockaddr_t* addr, socklen_t addrlen) const {
        if (((attached_t)unattached) != (detached)) {
        }
        return false;
    }
    virtual bool bind_detached
    (attached_t detached, const sockaddr_t* addr, socklen_t addrlen) const {
        if (((attached_t)unattached) != (detached)) {
        }
        return false; 
    }
    virtual bool accept_detached
    (attached_t detached, implemented::interface& sock, sockaddr_t* addr, socklen_t& addrlen) const {
        if (((attached_t)unattached) != (detached)) {
        }
        return false; 
    }
    virtual bool listen_detached(attached_t detached, backlog_t backlog) const { 
        if (((attached_t)unattached) != (detached)) {
        }
        return false; 
    }

    /// send... / recv... detached
    virtual ssize_t send_detached
    (attached_t detached, const void* buf, size_t len, send_flags_t flags) const {
        if ((((attached_t)unattached) != (detached)) && (buf) && (len)) {
        }
        return -1;
    }
    virtual ssize_t recv_detached
    (attached_t detached, void* buf, size_t len, recv_flags_t flags) const {
        if ((((attached_t)unattached) != (detached)) && (buf) && (len)) {
        }
        return -1;
    }
    virtual ssize_t sendto_detached
    (attached_t detached, const void* buf, size_t len, send_flags_t flags, const sockaddr_t* addr, socklen_t addrlen) {
        if ((((attached_t)unattached) != (detached)) 
            && (buf) && (len) && (addr) && (addrlen)) {
        }
        return -1;
    }
    virtual ssize_t recvfrom_detached
    (attached_t detached, void* buf, size_t len, recv_flags_t flags, sockaddr_t* addr, socklen_t* addrlen) {
        if ((((attached_t)unattached) != (detached)) 
            && (buf) && (len) && (addr) && (addrlen)) {
        }
        return -1;
    }

    /// ...opt_detached
    virtual bool set_opt_detached
    (attached_t detached, opt_level_t level, opt_name_t name, const void* value, socklen_t length) {
        if ((((attached_t)unattached) != (detached)) && (value) && (0 < length)) {
        }
        return false;
    }
    virtual bool get_opt_detached
    (attached_t detached, opt_level_t level, opt_name_t name, void* value, socklen_t &length) const {
        if ((((attached_t)unattached) != (detached)) && (value)) {
        }
        return false;
    }
}; /// class interfacet
typedef interfacet<> interface;
} /// namespace extended

} /// namespace sockets 
} /// namespace network 
} /// namespace xos 

#endif /// ndef XOS_NETWORK_SOCKETS_INTERFACE_HPP
