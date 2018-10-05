from conans import ConanFile
import os

class TM_CommonCPP_Conan(ConanFile):
    name = "TM_CommonCPP"
    version = "0.1"
    license = "MIT"
    url = "https://github.com/Troy1010/TM_CommonCPP"
    description = "TMinus1010's common C++ library."

    def source(self):
        self.run("git clone -b beta https://github.com/Troy1010/TM_CommonCPP.git")
        self.run("git clone https://github.com/SergiusTheBest/plog.git")

    def package(self):
        self.copy("*.h", dst="include", src="TM_CommonCPP/TM_CommonCPP/include")
        self.copy("*.h", dst="include", src="plog/include")

    def package_info(self):
        self.cpp_info.includedirs = ['include']
