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
///   File: main.hpp
///
/// Author: $author$
///   Date: 6/22/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_UUID_MAIN_HPP
#define XOS_APP_CONSOLE_UUID_MAIN_HPP

#include "xos/app/console/uuid/main_opt.hpp"
#include "xos/network/universal/unique/os/identifier.hpp"

#if !defined(DEBUG_ERRLLN)
#if defined(DEBUG_BUILD)
#define DEBUG_ERRLLN(__message__,...) this->errlln(__message__, ##__VA_ARGS__)
#else /// defined(DEBUG_BUILD)
#define DEBUG_ERRLLN(__message__,...)
#endif /// defined(DEBUG_BUILD)
#endif /// !defined(DEBUG_ERRLLN)

namespace xos {
namespace app {
namespace console {
namespace uuid {

/// class maint
template
<class TExtends = xos::app::console::uuid::main_optt<>,  class TImplements = typename TExtends::implements>

class maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint(): run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

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

    /// ...generate_uuid_run
    virtual int default_generate_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::network::universal::unique::identifier &uuid = this->uuid();
        int ethernet_index = this->ethernet_index();
        signed_to_string index(ethernet_index);

        LOGGER_IS_LOGGED_INFO("uuid.generate(index = " << index << ")...");
        if ((uuid.generate(ethernet_index))) {
            const char_t* chars = 0; size_t length = 0;

            LOGGER_IS_LOGGED_INFO("...uuid.generate(index = " << index << ")");
            LOGGER_IS_LOGGED_INFO("uuid.string().has_chars(length)...");
            if ((chars = uuid.string().has_chars(length))) {
                const bool& output_lf = this->output_lf();

                LOGGER_IS_LOGGED_INFO("...\"" << chars << "\" = uuid.string().has_chars("<< length <<")");
                this->output_text(chars, length, output_lf);
            } else {
                LOGGER_IS_LOGGED_ERROR("...unexpected !(chars = uuid.string().has_chars(length))");
            }
        } else {
            LOGGER_IS_LOGGED_ERROR("...failed on uuid.generate(index = " << index << ")");
        }
        return err;
    }

    /// ...uuid
    virtual xos::network::universal::unique::identifier &uuid() const {
        return (xos::network::universal::unique::identifier&)uuid_;
    }

protected:
    xos::network::universal::unique::os::identifier uuid_;
}; /// class maint
typedef maint<> main;

} /// namespace uuid
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_UUID_MAIN_HPP
