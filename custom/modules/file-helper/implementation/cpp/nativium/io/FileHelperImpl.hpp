#pragma once

#include "nativium/io/FileHelper.hpp"
#include "nativium/io/FileHelperPlatformService.hpp"

namespace nativium
{
namespace io
{

class FileHelperImpl : public FileHelper
{

public:
    FileHelperImpl();
    static std::shared_ptr<FileHelperImpl> internalSharedInstance();

    void setPlatformService(const std::shared_ptr<FileHelperPlatformService> &ps) override;
    std::shared_ptr<FileHelperPlatformService> getPlatformService() override;
    bool hasPlatformService() override;

private:
    static std::shared_ptr<FileHelperImpl> instance;
    std::shared_ptr<FileHelperPlatformService> ps;
};

} // namespace io
} // namespace nativium
