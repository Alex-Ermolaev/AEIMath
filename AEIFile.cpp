//C++
//AEIFile
//Developed by Abionics
//email: abionics.dev@gmail.com

#ifndef _ABIOTOPIA_AEIFile
#define _ABIOTOPIA_AEIFile

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

class AEIFile;

class AEIFileRWable {
public:
    virtual void write(AEIFile* file) const = 0;
    virtual void read(AEIFile* file) = 0;
};

class AEIFile : public std::fstream {
public:
    static bool create;
    explicit AEIFile(const char* str, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out) {
        open(str, mode);
        if (is_open()) return;
        if (create) {
            std::ofstream _(str);
            open(str, mode);
            if (is_open()) return;
            throw "AEIFile: File dont exist and cant be created!";
            return;
        }
        throw "AEIFile: File dont exist!";
    }

    void begin() { seekg(0, std::ios::beg); }
    void end() { seekg(0, std::ios::end); }
    long size() {
        streamoff pos = tellg();
        seekg(0, std::ios::end);
        long size = tellg();
        seekg(pos);
        return size;
    }

    void awrite(const short value) {
        write((char *) &value, sizeof(short));
    }
    void awrite(const int value) {
        write((char *) &value, sizeof(int));
    }
    void awrite(const long value) {
        write((char *) &value, sizeof(long));
    }
    void awrite(const long long value) {
        write((char *) &value, sizeof(long long));
    }
    void awrite(const float value) {
        write((char *) &value, sizeof(float));
    }
    void awrite(const double value) {
        write((char *) &value, sizeof(double));
    }
    void awrite(const long double value) {
        write((char *) &value, sizeof(long double));
    }
    void awrite(const bool value) {
        write((char *) &value, sizeof(bool));
    }
    void awrite(const char value) {
        write((char *) &value, sizeof(char));
    }
    void awrite(const wchar_t value) {
        write((char *) &value, sizeof(wchar_t));
    }
    void awrite(const char16_t value) {
        write((char *) &value, sizeof(char16_t));
    }
    void awrite(const char32_t value) {
        write((char *) &value, sizeof(char32_t));
    }
    void awrite(const char* value) {
        size_t len = strlen(value);
        write((char*)&len, sizeof(size_t));
        write((char*)value, len);
    }
    void awrite(const std::string& value) {
        size_t len = value.size();
        write((char*)&len, sizeof(size_t));
        write(value.c_str(), len);
    }
    template <typename T>
    void awrite(const std::vector<T>& value) {
        size_t cnt = value.size();
        write((char*)&cnt, sizeof(size_t));
        for (const T& i : value)
            awrite(i);
    }
    template <typename T>
    void awrite(const std::set<T>& value) {
        size_t cnt = value.size();
        write((char*)&cnt, sizeof(size_t));
        for (const T& i : value)
            awrite(i);
    }
    template <typename T1, typename T2>
    void awrite(const std::pair<T1,T2>& value) {
        awrite(value.first);
        awrite(value.second);
    }
    template <typename T1, typename T2>
    void awrite(const std::map<T1,T2>& value) {
        size_t cnt = value.size();
        write((char*)&cnt, sizeof(size_t));
        for (const auto& i : value)
            awrite(i);
    }
    void awrite(const AEIFileRWable& value) {
        value.write(this);
    }

    void aread(short& value) {
        read((char *) &value, sizeof(short));
    }
    void aread(int& value) {
        read((char *) &value, sizeof(int));
    }
    void aread(long& value) {
        read((char *) &value, sizeof(long));
    }
    void aread(long long& value) {
        read((char *) &value, sizeof(long long));
    }
    void aread(float& value) {
        read((char *) &value, sizeof(float));
    }
    void aread(double& value) {
        read((char *) &value, sizeof(double));
    }
    void aread(long double& value) {
        read((char *) &value, sizeof(long double));
    }
    void aread(bool& value) {
        read((char *) &value, sizeof(bool));
    }
    void aread(char& value) {
        read((char *) &value, sizeof(char));
    }
    void aread(wchar_t& value) {
        read((char *) &value, sizeof(wchar_t));
    }
    void aread(char16_t& value) {
        read((char *) &value, sizeof(char16_t));
    }
    void aread(char32_t& value) {
        read((char *) &value, sizeof(char32_t));
    }
    void aread(char*& value) {
        size_t len;
        read((char*)&len, sizeof(size_t));
        value = new char[len+1];
        read(value, len);
        value[len] = '\0';
    }
    void aread(std::string& value) {
        size_t len;
        read((char*)&len, sizeof(size_t));
        char* tmp = new char[len+1];
        read(tmp, len);
        tmp[len] = '\0';
        value = tmp;
        delete [] tmp;
    }
    template <typename T>
    void aread(std::vector<T>& value) {
        size_t cnt;
        read((char*)&cnt, sizeof(size_t));
        value.resize(cnt);
        for (int i = 0; i < cnt; i++)
            aread(value[i]);
    }
    template <typename T>
    void aread(std::set<T>& value) {
        size_t cnt;
        read((char*)&cnt, sizeof(size_t));
        T tmp;
        value.clear();
        for (int i = 0; i < cnt; i++) {
            aread(tmp);
            value.emplace_hint(value.end(), tmp);
        }
    }
    template <typename T1, typename T2>
    void aread(std::pair<T1,T2>& value) {
        aread(value.first);
        aread(value.second);
    }
    template <typename T1, typename T2>
    void aread(std::map<T1,T2>& value) {
        size_t cnt;
        read((char*)&cnt, sizeof(size_t));
        std::pair<T1,T2> tmp;
        value.clear();
        for (int i = 0; i < cnt; i++) {
            aread(tmp);
            value.emplace_hint(value.end(), tmp);
        }
    }
    void aread(AEIFileRWable& value) {
        value.read(this);
    }

    ~AEIFile() override {
        close();
    }
};
bool AEIFile::create = false;

class AEIFileEtc : public AEIFile {
    explicit AEIFileEtc(const char* str, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out) : AEIFile(str, mode) {}

    template<typename T>
    void awrite(const T& value) {
        write((char *) &value, sizeof(T));
    }

    template<typename T>
    void aread(T& value) {
        read((char *) &value, sizeof(T));
    }

    ~AEIFileEtc() override {
        AEIFile::~AEIFile();
    }
};

#endif  // _ABIOTOPIA_AEIFile


/*
          Example of RWable class

class ExampleClass : public AEIFileRWable {
    string str;
    int x;
public:
    ExampleClass() : str("It is a class"), x(35) {}
    void write(AEIFile* file) const override {
        file->awrite(str);
        file->awrite(x);
    }
    void read(AEIFile* file) override {
        file->aread(str);
        file->aread(x);
    }
};
 */
