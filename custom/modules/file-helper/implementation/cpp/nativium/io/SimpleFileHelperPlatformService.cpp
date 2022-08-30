#include "SimpleFileHelperPlatformService.hpp"

#ifndef __EMSCRIPTEN__
#include "Poco/DirectoryIterator.h"
#include "Poco/File.h"
#include "Poco/FileStream.h"
#include "Poco/Path.h"
#include "Poco/StreamCopier.h"
#include "Poco/URI.h"
#else
#include <filesystem>
#endif

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace nativium
{
namespace io
{

bool SimpleFileHelperPlatformService::createFile(const std::string &path)
{
    try
    {
#ifdef __EMSCRIPTEN__
        std::ofstream stream;
        stream.open(path);
        stream.close();

        return true;
#else
        Poco::File f(path);
        return f.createFile();
#endif
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::createFileWithStringContent(const std::string &path, const std::string &content)
{
    try
    {
        std::ofstream stream;
        stream.open(path, std::ios::out | std::ios::binary | std::ios::trunc);
        stream << content;
        stream.close();

        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::createFileWithBinaryContent(const std::string &path, const std::vector<uint8_t> &content)
{
    try
    {
        std::ofstream stream;
        stream.open(path, std::ios::out | std::ios::binary);

        for (auto &data : content)
        {
            stream << data;
        }

        stream.close();

        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::createDir(const std::string &path)
{
    try
    {
#ifdef __EMSCRIPTEN__
        std::filesystem::create_directories(path);
#else
        Poco::File f(path);
        f.createDirectories();
#endif

        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}

std::vector<std::string> SimpleFileHelperPlatformService::listFiles(const std::string &path)
{
    try
    {
        std::vector<std::string> files;

#ifdef __EMSCRIPTEN__
        for (const auto &entry : std::filesystem::directory_iterator(path))
        {
            files.push_back(entry.path());
        }
#else
        Poco::DirectoryIterator d(path);
        d->list(files);
#endif

        return files;
    }
    catch (const std::exception &)
    {
        return {};
    }
}

std::string SimpleFileHelperPlatformService::getExtension(const std::string &path)
{
    try
    {
#ifdef __EMSCRIPTEN__
        return std::filesystem::path(path).extension();
#else
        Poco::Path p(path);
        return p.getExtension();
#endif
    }
    catch (const std::exception &)
    {
        return "";
    }
}

std::string SimpleFileHelperPlatformService::getFilename(const std::string &path)
{
    try
    {
#ifdef __EMSCRIPTEN__
        return std::filesystem::path(path).filename();
#else
        Poco::Path p(path);
        return p.getFileName();
#endif
    }
    catch (const std::exception &)
    {
        return "";
    }
}

std::string SimpleFileHelperPlatformService::getBasename(const std::string &path)
{
    try
    {
#ifdef __EMSCRIPTEN__
        return std::filesystem::path(path).stem();
#else
        Poco::Path p(path);
        return p.getBaseName();
#endif
    }
    catch (const std::exception &)
    {
        return "";
    }
}

std::string SimpleFileHelperPlatformService::getFilenameFromUrl(const std::string &url)
{
    try
    {
#ifdef __EMSCRIPTEN__
        return std::filesystem::path(url).filename();
#else
        Poco::URI u(url);
        return Poco::Path(u.getPath()).getFileName();
#endif
    }
    catch (const std::exception &)
    {
        return "";
    }
}

std::string SimpleFileHelperPlatformService::getBasenameFromUrl(const std::string &url)
{
    try
    {
#ifdef __EMSCRIPTEN__
        return std::filesystem::path(url).stem();
#else
        auto filename = getFilenameFromUrl(url);
        return Poco::Path(filename).getBaseName();
#endif
    }
    catch (const std::exception &)
    {
        return "";
    }
}

bool SimpleFileHelperPlatformService::removeFile(const std::string &path)
{
    try
    {
#ifdef __EMSCRIPTEN__
        return std::filesystem::remove(path);
#else
        Poco::File f(path);
        f.remove(false);
        return true;
#endif
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::removeDir(const std::string &path)
{
    try
    {
#ifdef __EMSCRIPTEN__
        return std::filesystem::remove_all(path);
#else
        Poco::File f(path);
        f.remove(true);
        return true;
#endif
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::isDir(const std::string &path)
{
    try
    {
#ifdef __EMSCRIPTEN__
        return std::filesystem::is_directory(path);
#else
        Poco::File f(path);
        return f.isDirectory();
#endif
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::isFile(const std::string &path)
{
    try
    {
#ifdef __EMSCRIPTEN__
        return std::filesystem::is_regular_file(path);
#else
        Poco::File f(path);
        return f.isFile();
#endif
    }
    catch (const std::exception &)
    {
        return false;
    }
}

int64_t SimpleFileHelperPlatformService::getFileSize(const std::string &path)
{
    try
    {
#ifdef __EMSCRIPTEN__
        return static_cast<int64_t>(std::filesystem::file_size(path));
#else
        Poco::File f(path);
        return static_cast<int64_t>(f.getSize());
#endif
    }
    catch (const std::exception &)
    {
        return 0;
    }
}

bool SimpleFileHelperPlatformService::copyFile(const std::string &from, const std::string &to)
{
    try
    {
#ifdef __EMSCRIPTEN__
        std::filesystem::copy(from, to);
#else
        Poco::File f(from);
        f.copyTo(to);
#endif

        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}

bool SimpleFileHelperPlatformService::moveFile(const std::string &from, const std::string &to)
{
    try
    {
#ifdef __EMSCRIPTEN__
        std::filesystem::rename(from, to);
#else
        Poco::File f(from);
        f.moveTo(to);
#endif

        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}

std::string SimpleFileHelperPlatformService::join(const std::string &first, const std::string &second)
{
    try
    {
#ifdef __EMSCRIPTEN__
        return std::filesystem::path(first) / std::filesystem::path(second);
#else
        Poco::Path p(first, second);
        return p.toString();
#endif
    }
    catch (const std::exception &)
    {
        return "";
    }
}

std::string SimpleFileHelperPlatformService::getFileContentAsString(const std::string &path)
{
    try
    {
        std::ifstream stream(path, std::ios::in | std::ios::binary);

        if (!stream.is_open())
        {
            return "";
        }

        std::string contents{std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>()};

        stream.close();

        return contents;
    }
    catch (const std::exception &)
    {
        return "";
    }
}

std::vector<uint8_t> SimpleFileHelperPlatformService::getFileContentAsBinary(const std::string &path)
{
    try
    {
        std::ifstream stream(path, std::ios::in | std::ios::binary);

        if (!stream.is_open())
        {
            return {};
        }

        std::vector<uint8_t> contents((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

        stream.close();

        return contents;
    }
    catch (const std::exception &)
    {
        return {};
    }
}

std::string SimpleFileHelperPlatformService::getHomeDir()
{
#ifdef __EMSCRIPTEN__
    return "/";
#else
    return Poco::Path::home();
#endif
}

} // namespace io
} // namespace nativium
