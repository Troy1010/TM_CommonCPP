from conans import ConanFile
import os

class TM_CommonCPP_Conan(ConanFile):
    name = "TM_CommonCPP"
    version = "0.1"
    license = ""
    url = "https://github.com/Troy1010/TM_CommonCPP"
    description = "TMinus1010's common C++ library."
    requires="Plog/0.1@Troy1010/channel"
    generators="visual_studio"
    exports = "RecommendedIntegration.py"

    def source(self):
        self.run("git clone -b dev https://github.com/Troy1010/TM_CommonCPP.git")

    def package(self):
        self.copy("RecommendedIntegration.py")
        self.copy("*.h", dst="include", src="TM_CommonCPP/TM_CommonCPP/include")
        self.copy("*", dst="TM_CommonCPP", src="TM_CommonCPP")

    def package_info(self):
        self.cpp_info.includedirs = ['include']
