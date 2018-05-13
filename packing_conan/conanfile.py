from conans import ConanFile


class TM_CommonCPP_Conan(ConanFile):
    name = "OBSEPluginDevPackage"
    version = "1.2"
    license = "None"
    url = "https://github.com/Troy1010/TM_CommonCPP"
    description = "TMinus1010's common C++ library."

    def source(self):
        self.run("git clone https://github.com/memsharded/hello.git")
        self.run("cd hello && git checkout static_shared")

    def package(self):
        self.copy("*.h", src="../TM_CommonCPP/include", dst="include")
        self.copy("*.h", src="../submodules/plog/include", dst="include")

    def package_info(self):
        self.cpp_info.includedirs = ['include']
