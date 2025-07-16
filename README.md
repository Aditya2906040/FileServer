# FileServer

Sockit is a fileserver using custom created TCP sockets using C++

#Overview
SockIt is a terminal-based file sharing system built in C++. It allows file transfers over TCP sockets, supporting upload, download, and file listing. This project is developed in phases, starting with a single-client blocking model and later extending to multiclient support and GUI integration.

#System Architecture

[Terminal Client] ⇄ TCP Socket ⇄ [Terminal Server]

-Client: C++ terminal program that provides a menu and interacts with the user.

-Server: C++ terminal program that handles one client at a time, processes file commands, and manages files.

#Phase 1: Blocking Single-Client Model (Current phase)
Features Implemented

    -Establish TCP connection (client to server)

    -Handle one client at a time (blocking)

    -Support the LIST command:

        +Client sends LIST

        +Server responds with list of filenames in a shared directory

    -Simple line-based protocol

    -Graceful client disconnection (EXIT command)

#Commands & Protocol
-Client → Server

    LIST\n

-Server → Client

    file1.txt\n
    file2.jpg\n
    image.pdf\n
    EOF\n

    All messages are newline-terminated (\n)

    "EOF\n" marks end of file list

#Technologies Used

| Area       | Tool / API             | Notes                         |
| ---------- | ---------------------- | ----------------------------- |
| Networking | BSD Sockets / Winsock  | Blocking sockets              |
| File I/O   | `ifstream`, `ofstream` | Binary-safe operations        |
| Directory  | `<filesystem>` (C++17) | For `LIST` functionality      |
| CLI        | Standard input/output  | Text-based interface          |
| OS Support | Windows / Linux        | Platform-specific socket init |

#User Experience
![Image of menu](image.png)
