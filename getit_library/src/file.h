

#ifndef GETIT_FILE_H
#define GETIT_FILE_H

#include <iface.h>
#include <chrono>

namespace getit
{
    class File final: public FileIface
    {
	    std::string path_;
	    mutable std::time_t last_read_time_;

	public:
	    File ( std::string const& path_);
	    getit::FileState is_modified() const override;
	    file_lines_t getlines() const override;
	    void putlines( file_lines_t const& ) const override;
	    std::string path() const;
    };

    class Directory final: public DirectoryIface
    {
	public:
	    virtual file_list_t getfiles( std::string const& path, std::string const& mask) const override;
    };
}
#endif // GETIT_FILE_H

