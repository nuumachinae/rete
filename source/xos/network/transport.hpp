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
///   File: transport.hpp
///
/// Author: $author$
///   Date: 9/3/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_TRANSPORT_HPP
#define XOS_NETWORK_TRANSPORT_HPP

#include "xos/base/logged.hpp"

namespace xos {
namespace network {

typedef int transport_domain_t;
enum { transport_domain_unspec = 0 };

typedef int transport_type_t;
enum { transport_type_unspec = 0 };

typedef int transport_protocol_t;
enum { transport_protocol_unspec = 0 };

/// class transportt
template 
<typename TDomain = transport_domain_t, TDomain VDomainUnspec = transport_domain_unspec,
 typename TType = transport_type_t, TType VTypeUnspec = transport_type_unspec,
 typename TProtocol = transport_protocol_t, TProtocol VProtocolUnspec = transport_protocol_unspec,
 class TImplements = logged>

class exported transportt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef transportt derives;

    typedef TDomain domain_t;
    enum { domain_unspec = VDomainUnspec };

    typedef TType type_t;
    enum { type_unspec = VTypeUnspec };

    typedef TProtocol protocol_t;
    enum { protocol_unspec = VProtocolUnspec };

    /// domain / type / protocol
    virtual domain_t domain() const {
        return domain_unspec;
    }
    virtual type_t type() const {
        return type_unspec;
    }
    virtual protocol_t protocol() const {
        return protocol_unspec;
    }
}; /// class transportt
typedef transportt<> transport;

namespace extended {
/// class transportt
template <class TExtends = xos::extended::logged, class TImplements = network::transport>
class exported transportt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef transportt derives;

    typedef typename implements::domain_t domain_t;
    enum { domain_unspec = implements::domain_unspec };
    
    typedef typename implements::type_t type_t;
    enum { type_unspec = implements::type_unspec };
    
    typedef typename implements::protocol_t protocol_t;
    enum { protocol_unspec = implements::protocol_unspec };

    /// constructor / destructor
    transportt(const transportt& copy): extends(copy) {
    }
    transportt() {
    }
    virtual ~transportt() {
    }
}; /// class transportt
typedef transportt<> transport;
} /// namespace extended

} /// namespace network 
} /// namespace xos 

#endif /// ndef XOS_NETWORK_TRANSPORT_HPP
