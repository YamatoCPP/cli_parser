
from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps, cmake_layout

class CliParser(ConanFile):
    name: str = "cli_parser"
    version: str = "1.0"
    settings: tuple = "os", "compiler", "build_type", "arch"
    
    options: dict = {
        "shared": [False, True]
    }

    default_options: dict = {
        "shared": False
    }
    
    exports_sources: list[str] = ["CMakeLists.txt", "modules/*", "src/*"]

    def layout(self) -> None:
        cmake_layout(self)
        
    def build_requirements(self) -> None:
        self.tool_requires("cmake/4.1.2")
        self.test_requires("gtest/1.17.0")

    def generate(self) -> None:
        dp: CMakeDeps = CMakeDeps(self)
        dp.generate()

        tc: CMakeToolchain = CMakeToolchain(self)
        tc.generator = "Ninja"
        tc.generate()

    def build(self) -> None:
        cmake: CMake = CMake(self)
        cmake.configure()
        cmake.build()
    
    def package(self) -> None:
        cmake: CMake = CMake(self)
        cmake.install()
    
    def package_info(self) -> None:
        self.cpp_info.libs = ["cli_parser"]
        self.cpp_info.includedirs = ["modules"]
        self.cpp_info.set_property("cmake_bmi_dir", "modules/bmi")
