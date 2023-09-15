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
///   Date: 9/3/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_ENDPOINT_HPP
#define XOS_NETWORK_ENDPOINT_HPP

#include "xos/network/address.hpp"

namespace xos {
namespace network {

/// class endpointt
template <class TImplements = address>
class exported endpointt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef endpointt derives;

    typedef typename implements::family_t family_t;
    enum { family_unspec = implements::family_unspec };
    
    typedef typename implements::version_t version_t;
    enum { version_unspec = implements::version_unspec };

    /// family /  version
    virtual family_t family() const {
        return family_unspec;
    }
    virtual version_t version() const {
        return version_unspec;
    }
}; /// class endpointt
typedef endpointt<> endpoint;

namespace extended {
/// class endpointt
template 
<class TExtends = network::extended::address, class TImplements = network::endpoint>

class exported endpointt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef endpointt derives;

    typedef typename implements::family_t family_t;
    enum { family_unspec = implements::family_unspec };
    
    typedef typename implements::version_t version_t;
    enum { version_unspec = implements::version_unspec };

    /// constructor / destructor
    endpointt(const endpointt& copy): extends(copy) {
    }
    endpointt() {
    }
    virtual ~endpointt() {
    }
}; /// class endpointt
typedef endpointt<> endpoint;
} /// namespace extended

} /// namespace network 
} /// namespace xos 

#endif /// ndef XOS_NETWORK_ENDPOINT_HPP
