# input_without_overflow
A very simple solution to avoid overflow when more characters than expect are given to a read function

I'm trying to pass how my experience was in solving this problem. I apologize everyone since here if any grammar error is encountered. As you might know, I'm not a native english speaker. And much of my road to reach the solution was cut off, so.. all this is summed up.

At a long time, C standard functions, such as scanf, the fearsome gets, and even the considered secure fgets bothered me about one thing: when you give them more bytes that were intended to be read, those excedent characters are carried to the subsequent read functions of your program.

This effect is BAD, since it open some breaches to bugs and memory corruption. So, some basic undestanding about input streams must be known: in C, the stdin is the traditional buffer that holds data from the input. So, anything that you want give to a program, let's say, a number, a name, or any stream of bytes, must be stored in this file, and then passed to the function that receives them.

But, obviously, our programs only read to a specific point: until the '\n' is found (or in another words: when enter is pressed). Since we "call" stdin, nothing more can be done after writing some stuff/nothing and pressing enter. Every byte is read to this point.

Our problem rises when we give to a read function more characters than it should read. Try giving a simple scanf("%c", &char) a string. At a first glance, this harmless call doesn't produce any strange effect, since the first byte is read, and stored on the "char" variable. 

But, on larger programs that require more read functions, it would produce some effects as don't even request a user to give an input, just like it happened automatically.

But, under the hood, what really happens is: when you give more bytes than the function or variable can store, those remaining little monsters are still alive in the stdin, with the '\n' char you gave. So, if another call to stdin is made, this stream is read until the ENTER is encountered: the computer doens't know if this stream was given by you, or if it was still in memory.

I was trying by myself to encounter any solution to this problem: fgets, known to be a safe function, doens't avoid this behavior. Even when we give a maximum number of bytes to be read, the remaining continue on stdin, and if you call fgets again, the same happens. Trying to "clean" stdin with fflush does not produce any effect. So, another approach was necessary: as stdin is of type FILE, I could learn how to manage it by trying to make "my own stdin".

Most of the functions available to FILE aren't allowed to be used on stdin. And at this point it was the only thing I needed to solve this problem. 

So, ok, let's consider at this point that we have a string of size 10. If we call to stdin, by any read function, and give 14 chars, including ENTER, this string will be filled with the first 10 characters on stdin, and the remaining 4 are still on memory. So, this trash must be someway cleaned. Thinking about files in C, we always set it's pointer to the start, end, or any other place between them (search for "fseek" function). So, in order to ignore those exceeding bytes, the "pointer" of stdin must be set to AFTER the '\n' final character. But as known, fseek cannot be applied to stdin.

So, in light of all this, the only thing we must pursue is to get the stdin pointer after the final character, to set it as the stdin were empty. Our solution is near the end right now: the star behind all this is in the getchar function. It's behaviour is simple: it gets a character directly from stdin, and adjust its pointer to the next one. 

The only thing needed here is a loop which calls getchar until the last character reached is ENTER/'\n'. Since we try this after every call to stdin, this buffer is "cleaned" up to wait for another call, without any overflow.

The code is very simple, the only thing we should worry at this point is to guarantee that the string given to any read function is properly formatted.
