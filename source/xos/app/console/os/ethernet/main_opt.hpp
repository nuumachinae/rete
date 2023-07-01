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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 6/21/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_OS_ETHERNET_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_OS_ETHERNET_MAIN_OPT_HPP

#include "xos/app/console/ethernet/main.hpp"
#include "xos/network/ethernet/os/address.hpp"

namespace xos {
namespace app {
namespace console {
namespace os {
namespace ethernet {

/// class main_optt
template
<class TEthernetAddress = xos::network::ethernet::os::address,
 class TExtends = xos::app::console::ethernet::maint<>,  class TImplements = typename TExtends::implements>

class main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    typedef TEthernetAddress ethernet_address_t;

    /// run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    /// ...output_address_run
    virtual int output_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        unsigned index = this->interface_number();
        network::ethernet::address &ethernet = this->ethernet_address();
        network::ethernet::actual::address *address = 0;

        if ((address = ethernet.set_to_adapter(index))) {
            if (!(err = output_actual_address_text_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }

    /// ...output_name_run
    virtual int output_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        unsigned index = this->interface_number();
        network::ethernet::address &ethernet = this->ethernet_address();
        network::ethernet::actual::address *address = 0;

        if ((address = ethernet.set_to_adapter(index))) {
            this->outln(ethernet.adapter_name());
        }
        return err;
    }

    /// ...output_address_named_run
    virtual int output_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& name = this->interface_name();
        network::ethernet::address &ethernet = this->ethernet_address();
        network::ethernet::actual::address *address = 0;

        if ((address = ethernet.set_to_adapter(name))) {
            this->outln(ethernet.actual_string());
        }
        return err;
    }

    /// ...output_actual_address_text_run
    virtual int output_actual_address_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        network::ethernet::address &ethernet = this->ethernet_address();
        const char_t* chars = 0; size_t length = 0;

        LOGGER_IS_LOGGED_INFO("ethernet.actual_string().has_chars(length)...");
        if ((chars = ethernet.actual_string().has_chars(length))) {
            const bool& output_lf = this->output_lf();

            LOGGER_IS_LOGGED_INFO("...\"" << chars << "\" = ethernet.actual_string().has_chars("<< length <<")");
            this->output_text(chars, length, output_lf);
        } else {
            LOGGER_IS_LOGGED_ERROR("...unexpected !(chars = ethernet.actual_string().has_chars(length))");
        }
        return err;
    }

    /// ...ethernet_address
    virtual network::ethernet::address& ethernet_address() const {
        return (network::ethernet::address&)ethernet_address_;
    }

protected:
    ethernet_address_t ethernet_address_;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace ethernet
} /// namespace os
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_OS_ETHERNET_MAIN_OPT_HPP
