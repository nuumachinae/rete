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
///   Date: 6/21/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_NETWORK_ETHERNET_OS_OS_HPP
#define XOS_NETWORK_ETHERNET_OS_OS_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace network {
namespace ethernet {
namespace bsd {} /// namespace bsd
namespace systemv {} /// namespace systemv
namespace os {

#if defined(BSD)
namespace os = bsd;
#elif defined(SYSTEMV)
namespace os = systemv;
#else /// defined(BSD)
#error only supported on BSD or SystemV operating systems
#endif /// defined(BSD)

} /// namespace os
} /// namespace ethernet
} /// namespace network
} /// namespace xos

#endif /// ndef XOS_NETWORK_ETHERNET_OS_OS_HPP
