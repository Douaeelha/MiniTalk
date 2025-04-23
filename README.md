This project dives into UNIX system calls and signals, and it challenged me to think at the bit-level.
🛠️ Project Overview:

The goal was to create two executables:

    Client – sends a message

    Server – receives and reconstructs it

But here's the twist the communication happens entirely through signals. Specifically, we used two user-defined signals to transmit messages bit by bit.
💡 What I Learned:

    How system calls and signals work in UNIX

    How to encode and decode data bit by bit

    Working with bit shifting for the first time — and it was genuinely fun!

    Improved my understanding of Makefiles and how to structure them cleanly
