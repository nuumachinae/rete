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
///   Date: 9/3/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_INTERFACE_HPP
#define XOS_NETWORK_INTERFACE_HPP

#include "xos/base/logged.hpp"
#include "xos/base/opened.hpp"
#include "xos/network/transport.hpp"

namespace xos {
namespace network {

namespace sockets {
class exported interface;
} /// namespace sockets

/// class interfacet
template <class TImplements = loggedt<opener> >
class exported interfacet: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef interfacet derives;

    /// open / close
    virtual bool open(const transport& tp) {
        return false;
    }
    virtual bool close() {
        return false;
    }
    
    /// ...sockets_interface
    virtual const sockets::interface* const_sockets_interface() const {
        return this->sockets_interface();
    }
    virtual sockets::interface* sockets_interface() const {
        return 0;
    }
}; /// class interfacet
typedef interfacet<> interface;

namespace extended {
/// class interfacet
template 
<typename TAttached = pointer_t, 
 typename TUnattached = int, TUnattached VUnattached = 0,
 class TImplements = network::interface, class TExtends = openedt
 <TAttached, TUnattached, VUnattached, TImplements> >

class exported interfacet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef interfacet derives;

    typedef TAttached attached_t;
    typedef TUnattached unattached_t;
    enum { unattached = VUnattached };

    /// constructor / destructor
    interfacet(attached_t detached, bool is_open): extends(detached, is_open) {
    }
    interfacet(attached_t detached): extends(detached) {
    }
    interfacet(const interfacet& copy): extends(copy) {
    }
    interfacet() {
    }
    virtual ~interfacet() {
    }
}; /// class interfacet
typedef interfacet<> interface;
} /// namespace extended

} /// namespace network 
} /// namespace xos 

#endif /// ndef XOS_NETWORK_INTERFACE_HPP
