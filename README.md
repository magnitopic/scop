# scop

Graphical project for rendering 3D objects using OpenGL.

## Dependencies

- GLFW 3 — window and input
- GLAD — OpenGL function loader (bundled in `src/glad.c` and `include/glad/`)
- OpenGL 3.3 core profile driver

## Linux setup

### 1. Install GLFW and OpenGL system packages

```bash
sudo apt-get install libglfw3-dev libgl-dev
```

### 2. Bundle GLAD

GLAD was generated with the [glad v1 Python generator](https://pypi.org/project/glad/) for OpenGL 3.3 core and committed directly to the repository under `include/glad/`, `include/KHR/`, and `src/glad.c`.

To regenerate them yourself:

```bash
python3 -m pip install --user glad
python3 -m glad --generator=c --spec=gl --profile=core --api="gl=3.3" --extensions="" --out-path=/tmp/glad_out
cp /tmp/glad_out/include/glad/glad.h include/glad/glad.h
cp /tmp/glad_out/include/KHR/khrplatform.h include/KHR/khrplatform.h
cp /tmp/glad_out/src/glad.c src/glad.c
```

### 3. Build

```bash
make
```

## macOS setup (Homebrew)

```bash
brew install glfw
make
```

## Run

```bash
./scop
```
