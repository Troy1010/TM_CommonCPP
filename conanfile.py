from conans import ConanFile, MSBuild


class TM_CommonCPP_Conan(ConanFile):
    name = "TM_CommonCPP"
    version = "0.1"
    license = "MIT"
    url = "https://github.com/Troy1010/TM_CommonCPP"
    description = "TMinus1010's common C++ library."
    requires = "Plog/0.1@Troy1010/channel"
    generators = "visual_studio"
    # MSBuild is nonfunctional without this line
    settings = "os", "compiler", "build_type", "arch"

    def source(self):
        self.run("git clone -b beta https://github.com/Troy1010/TM_CommonCPP.git")

    def build(self):
        vMSBuild = MSBuild(self)
        vMSBuild.build("TM_CommonCPP/TM_CommonCPP/TM_CommonCPP_Lib.vcxproj")

    def package(self):
        self.copy("*.h", dst="include", src="TM_CommonCPP/TM_CommonCPP/include")
        self.copy("*.lib", dst="lib", src="TM_CommonCPP", keep_path=False)

    def package_info(self):
        self.cpp_info.includedirs = ['include']
        self.cpp_info.libdirs = ['lib']
        self.cpp_info.libs = ['TM_CommonCPP_Lib.lib']
