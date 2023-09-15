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
///   File: os.hpp
///
/// Author: $author$
///   Date: 9/9/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_SOCKETS_OS_OS_HPP
#define XOS_NETWORK_SOCKETS_OS_OS_HPP

#include "xos/platform/build.hpp"

#if defined(WINDOWS)
#include "xos/network/sockets/microsoft/windows/os.hpp"
#else /// defined(WINDOWS)
#include "xos/network/sockets/posix/os.hpp"
#endif /// defined(WINDOWS)

namespace xos {
namespace network {
namespace sockets {
namespace microsoft { 
namespace windows { } /// namespace windows
} /// namespace microsoft
namespace posix {} /// namespace posix
namespace os {

#if defined(WINDOWS)
namespace os = microsoft::windows;
#else /// defined(WINDOWS)
namespace os = posix;
#endif /// defined(WINDOWS)

} /// namespace os 
} /// namespace sockets 
} /// namespace network 
} /// namespace xos 

#endif /// ndef XOS_NETWORK_SOCKETS_OS_OS_HPP
