# Drogon Server Example
Build a High Performance API In C++ With https://github.com/drogonframework/drogon

## Get Started
Requirements:
- vcpkg: https://vcpkg.io/en/getting-started.html
- cmake

```bash
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1
cmake --build build
./build/web

curl -s 'http://localhost:8888'
```

## TODO
- [x] Basic Project Setup
- [x] Basic API Mocking
- [ ] Postgres Impl
- [ ] Better Error Handling
