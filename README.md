# Basic CMake helper for this workspace

This repository contains several subprojects (for example the `lvgl/` folder). A small, minimal top-level `CMakeLists.txt` has been added to make simple out-of-source builds easier.

How to configure and build (from repository root):

```powershell
cmake -S . -B build -G "Ninja"        # configure
cmake --build build --parallel         # build
```

Options available when configuring:

- DBUILD_LVGL=ON/OFF — add or skip the `lvgl/` subdirectory if it exists.
- DBUILD_EXAMPLES=ON/OFF — add or skip top-level `examples/` (if present).

This file is intentionally lightweight; adapt or extend it if you need to build specific demo apps or tests.
