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
///   Date: 9/7/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_SOCKETS_IP_ENDPOINT_HPP
#define XOS_NETWORK_SOCKETS_IP_ENDPOINT_HPP

#include "xos/network/sockets/ip/address.hpp"
#include "xos/network/sockets/endpoint.hpp"

namespace xos {
namespace network {
namespace sockets {
namespace ip {

/// class endpointt
template <class TImplements = sockets::endpoint>
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
}; /// class endpointt
typedef endpointt<> endpoint;

namespace extended {
/// class endpointt
template <class TExtends = sockets::extended::endpoint, class TImplements = ip::endpoint>
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
}; /// class endpointt
typedef endpointt<> endpoint;
} /// namespace extended

} /// namespace ip 
} /// namespace sockets 
} /// namespace network 
} /// namespace xos 

#endif /// ndef XOS_NETWORK_SOCKETS_IP_ENDPOINT_HPP
