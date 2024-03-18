# Raylib + RmlUi

- [Raylib](https://github.com/raysan5/raylib) is a thin wrapper around OpenGL using the inbuilt rlgl.
- [RmlUi](https://github.com/mikke89/RmlUi) is a XHTML 1.0 / CSS 2 renderer with ease of interaction with the elements.

## Examples

- [ ] Basic
  - [x] Animation
  - [x] Benchmark
  - [x] Bitmapfont
  - [x] Databinding
  - [ ] Demo
  - [ ] Drag
  - [ ] LoadDocuments
  - [ ] Lottie
  - [ ] SVG
  - [ ] Transform
  - [ ] Treeview
- [ ] Invaders
- [ ] Tutorial

## Building Examples

```shell
git submodule update --init --recursive
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Debug
cmake --build ./build -- -j $(nproc)
```

### Running examples

After building

- `cd bin/Debug`
- `./RmlUI_Example` or `./RmlUI_Example.exe` if on Windows

Other examples

- `./RaylibAnimation_Example`
- `./RaylibBenchmark_Example`
- `./RaylibBitmapfont_Example`
- `./RaylibDatabinding_Example`
