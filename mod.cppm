module;
#include <string>
export module TestModule;


export class ModuleTester {
public:
ModuleTester(const std::string & str = "From module") : m_name(str) {}
const char * name() const {return m_name.c_str();}
private:
std::string m_name;
};
