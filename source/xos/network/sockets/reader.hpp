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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 9/8/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_SOCKETS_READER_HPP
#define XOS_NETWORK_SOCKETS_READER_HPP

#include "xos/network/sockets/interface.hpp"
#include "xos/io/reader.hpp"
#include "xos/base/logger.hpp"

namespace xos {
namespace network {
namespace sockets {

typedef io::sequencet<sockchar_t, sockchar_t> sequence;
typedef io::seekert<sockets::sequence> seeker;

/// class readert
template 
<class TReader = io::readert<sockets::seeker>, 
 class TImplements = loggedt<TReader>, class TExtends = extend>
class exported readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef readert derives;

    typedef implements reader_t;
    typedef typename reader_t::what_t what_t;
    typedef typename reader_t::sized_t sized_t;

    /// constructor / destructor
    readert(const readert& copy): extends(copy), sock_(copy.sock_) {
    }
    readert(network::sockets::interface& sock): sock_(sock) {
    }
    virtual ~readert() {
    }
    
    /// read / recv
    virtual ssize_t read(what_t* what, size_t size) {
        ssize_t count = 0;
        if (1 < (sizeof(sized_t))) {
            LOGGER_IS_LOGGED_ERROR("...failed unsupported sizeof(sized_t) = " << sizeof(sized_t));
            return -1;
        }
        if (1 > (count = recv(what, size))) {
            return count;
        }
        return count;
    }
    virtual ssize_t recv(void* what, size_t size) {
        ssize_t count = 0;
        if ((what) && (size)) {
            count = sock_.recv(what, size, 0);
        }
        return count;
    }
    virtual network::sockets::interface& sock() const {
        return (network::sockets::interface&)sock_;
    }

protected:
    network::sockets::interface& sock_;
}; /// class readert
typedef readert<> reader;

} /// namespace sockets 
} /// namespace network 
} /// namespace xos 

#endif /// ndef XOS_NETWORK_SOCKETS_READER_HPP
