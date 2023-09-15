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
///   File: endpoint.hpp
///
/// Author: $author$
///   Date: 9/8/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_SOCKETS_IP_V4_ENDPOINT_HPP
#define XOS_NETWORK_SOCKETS_IP_V4_ENDPOINT_HPP

#include "xos/network/sockets/ip/v4/address.hpp"
#include "xos/network/sockets/ip/endpoint.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace ip {
namespace v4 {

/// sockaddr_t
typedef struct sockaddr_in sockaddr_t;

namespace implemented {
/// class endpointt
template <class TImplements = ip::endpoint>
class exported endpointt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef endpointt derives;

    typedef typename implements::attached_t attached_t;
    typedef typename implements::unattached_t unattached_t;
    enum { unattached = implements::unattached };
    
    typedef typename implements::implements::family_t family_t;
    enum { family_unspec = implements::implements::family_unspec };
    
    typedef typename implements::implements::version_t version_t;
    enum { version_unspec = implements::implements::version_unspec };

    /// family / version
    virtual family_t family() const {
        return AF_INET;
    }
    virtual version_t version() const {
        return 4;
    }
}; /// class endpointt
typedef endpointt<> endpoint;
} /// namespace implemented

/// class endpointt
template <class TExtends = ip::extended::endpoint, class TImplements = implemented::endpoint>
class exported endpointt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef endpointt derives;

    typedef typename implements::attached_t attached_t;
    typedef typename implements::unattached_t unattached_t;
    enum { unattached = implements::unattached };
    
    typedef typename implements::family_t family_t;
    enum { family_unspec = implements::family_unspec };
    
    typedef typename implements::version_t version_t;
    enum { version_unspec = implements::version_unspec };

    /// constructor / destructor
    endpointt(const string& host, sockport_t port) {
        if (!(this->attach(host, port))) {
            LOGGER_IS_LOGGED_ERROR("...throw attach_exception(attach_failed)...");
            throw attach_exception(attach_failed);
        }
    }
    endpointt(const char* host, sockport_t port) {
        if (!(this->attach(host, port))) {
            LOGGER_IS_LOGGED_ERROR("...throw attach_exception(attach_failed)...");
            throw attach_exception(attach_failed);
        }
    }
    endpointt(sockport_t port) {
        if (!(this->attach(port))) {
            LOGGER_IS_LOGGED_ERROR("...throw attach_exception(attach_failed)...");
            throw attach_exception(attach_failed);
        }
    }
    endpointt(const endpointt& copy): extends(copy) {
    }
    endpointt() {
    }
    virtual ~endpointt() {
        if ((this->attached_to())) {
            if (!(this->detach())) {
                LOGGER_IS_LOGGED_ERROR("...throw attach_exception(detach_failed)...");
                throw attach_exception(detach_failed);
            }
        }
    }
    
    /// attach
    using implements::attach;
    virtual attached_t attach(const attached_t saddr, socklen_t saddrlen, sockport_t port) {
        if ((saddr) && (saddrlen == (this->socket_address_len()))) {
            if (this->family() == (saddr->sa_family)) {
                attached_t attached = 0;
                if ((attached = this->attach(port))) {
                    const sockaddr_t& sockaddr = (const sockaddr_t&)(*saddr);
                    socket_address_.sin_addr.s_addr = sockaddr.sin_addr.s_addr;
                }
                return attached;
            }
        }
        return 0;
    }
    virtual attached_t attach(sockport_t port) {
        memset(&socket_address_, 0, this->socket_address_len_ = (this->socket_address_len()));
#if !defined(WINSOCK_1) && !defined(SYSTEMV)
        socket_address_.sin_len = this->socket_address_len_;
#else /// !defined(WINSOCK_1) && !defined(SYSTEMV)
#endif /// !defined(WINSOCK_1) && !defined(SYSTEMV)
        socket_address_.sin_family = this->family();
        socket_address_.sin_addr.s_addr = INADDR_ANY;
        socket_address_.sin_port = htons(this->socket_address_port_ = port);
        return extends::attach((attached_t)(&socket_address_));
    }
    virtual attached_t recv_socket_address(socklen_t& len) const {
        len = this->socket_address_len();
        return ((attached_t)&recv_socket_address_);
    }
    virtual socklen_t socket_address_len() const {
        return ((socklen_t)sizeof(socket_address_));
    }
    
protected:
    sockaddr_t socket_address_, recv_socket_address_;
}; /// class endpointt
typedef endpointt<> endpoint;

} /// namespace v4 
} /// namespace ip 
} /// namespace sockets 
} /// namespace network 
} /// namespace xos 

#endif /// ndef XOS_NETWORK_SOCKETS_IP_V4_ENDPOINT_HPP
