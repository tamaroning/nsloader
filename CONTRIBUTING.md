## LSP

1. Install clangd.
2. Create .clangd:

```
CompileFlags:
    CompilationDatabase: build/ 
```

3. Add include directorie to CompileFlags.Add if system headers are missing:
https://github.com/clangd/clangd/issues/97#issuecomment-511941923

In my case, .clangd should be:
```
CompileFlags:
    CompilationDatabase: build/
    Add: [
        -I/usr/include/c++/11,
        -I/usr/include/x86_64-linux-gnu/c++/11,
        -I/usr/include/c++/11/backward,
        -I/usr/lib/gcc/x86_64-linux-gnu/11/include,
        -I/usr/local/include,
        -I/usr/include/x86_64-linux-gnu,
        -I/usr/include,
    ]
```
