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
///   File: address.hpp
///
/// Author: $author$
///   Date: 9/3/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_ADDRESS_HPP
#define XOS_NETWORK_ADDRESS_HPP

#include "xos/base/string.hpp"
#include "xos/base/logged.hpp"

namespace xos {
namespace network {

typedef int address_family_t;
enum { address_family_unspec = 0 };

typedef int address_version_t;
enum { address_version_unspec = 0 };

/// class addresst
template 
<typename TFamily = address_family_t, TFamily VFamilyUnspec = address_family_unspec,
 typename TVersion = address_version_t, TVersion VVersionUnspec = address_version_unspec,
 class TImplements = logged>

class exported addresst: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef addresst derives;

    typedef TFamily family_t;
    enum { family_unspec = VFamilyUnspec };
    
    typedef TVersion version_t;
    enum { version_unspec = VVersionUnspec };

    /// family /  version
    virtual family_t family() const {
        return family_unspec;
    }
    virtual version_t version() const {
        return version_unspec;
    }
}; /// class addresst
typedef addresst<> address;

namespace extended {
/// class addresst
template 
<class TExtends = xos::extended::logged, class TImplements = network::address>

class exported addresst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef addresst derives;

    typedef typename implements::family_t family_t;
    enum { family_unspec = implements::family_unspec };
    
    typedef typename implements::version_t version_t;
    enum { version_unspec = implements::version_unspec };

    /// constructor / destructor
    addresst(const addresst& copy): extends(copy) {
    }
    addresst() {
    }
    virtual ~addresst() {
    }
}; /// class addresst
typedef addresst<> address;
} /// namespace extended

} /// namespace network 
} /// namespace xos 

#endif /// ndef XOS_NETWORK_ADDRESS_HPP
