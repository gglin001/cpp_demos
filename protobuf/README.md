# How to set protobuf library path

VSCode settings

`.vscode/settings.json`

```json
{
  "cmake.configureSettings": {
    "CMAKE_PREFIX_PATH": "/Users/allen/opt/miniconda3/envs/py36/lib",
    "Protobuf_INCLUDE_DIR": "/Users/allen/opt/miniconda3/envs/py36/include",
    "Protobuf_LIBRARY": "/Users/allen/opt/miniconda3/envs/py36/lib/libprotobuf.dylib",
    "Protobuf_PROTOC_LIBRARY": "/Users/allen/opt/miniconda3/envs/py36/lib/libprotoc.dylib",
    "Protobuf_LITE_LIBRARY": "/Users/allen/opt/miniconda3/envs/py36/lib/libprotobuf-lite.dylib",
    "Protobuf_PROTOC_EXECUTABLE": "/Users/allen/opt/miniconda3/envs/py36/bin/protoc"
  }
}
```
