Allowed functions:
◦ write
◦ ft_printf and any equivalent YOU coded
◦ signal
◦ sigemptyset
◦ sigaddset
◦ sigaction
◦ kill
◦ getpid
◦ malloc
◦ free
◦ pause
◦ sleep
◦ usleep
◦ exit

- The server must be started first. After its launch, it has to print its PID.
     ./server "Passing parameter
	 - prints out the PID number
- The client takes two parameters:
	◦ The server PID.
	◦ The string to send.

- The client must send the string passed as a parameter to the server.
- Once the string has been received, the server must print it.
	• The server has to display the string pretty quickly.

- Your server should be able to receive strings from several clients in a row without
needing to restart.

- The communication between your client and your server has to be done only using
UNIX signals: You can only use these two signals: SIGUSR1 and SIGUSR2.

💥 Important Note About Signals
Linux does NOT queue signals of the same type. That means:

If you send several SIGUSR1 or SIGUSR2 very fast, the server might miss some of them.

❗ Implication:
You must:

Send one signal at a time.

Wait for a small delay (usleep) or a response signal (ACK) before sending the next bit.

This is where pause() or acks via signal come in.