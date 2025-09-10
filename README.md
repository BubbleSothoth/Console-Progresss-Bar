# Console-Progresss-Bar
This is a simple wheel, providing a progresss bar in Console.

## How To Build
1. Clone or download the repositories.
    ```
   git clone https://github.com/BubbleSothoth/Console-Progresss-Bar
    ```
3. Open *ConsoleProgresssBar.sln* by Microsoft Visual Studio.
4. Build project in Microsoft Visual Studio.  
   Because of codes in project is really lightweight, I suggest building codes as *.lib* file.  
   The default building setting is *x86*, *Release*, *lib*.
## How To Use
About data-strucurets, there is a struct named *struct ProgressBar* or *PB* as abbreviation. *PB* record all infomation about the progress bar, including the max length of the bar, the character for fulling of the bar, etc.  
About functions, there are four APIs calling *CreateBar*, *RefreshBar*, *PrintBar*, *DeleteBar* and provided to create, modify, output, destory a progresss bar. You can find their declaration in *ConsoleProgresssBar.h* and defining in *ConsoleProgresssBar.cpp*.

### API Function: CreateBar
Prototype: 
```C
unsigned short CreateBar(PB* lpbar, float max_progress, unsigned int max_length, char full_char, char empty_char);
```
### API Function: RefreshBar
Prototype: 
```C
unsigned short RefreshBar(PB* lpbar, float progress);
```
### API Function: PrintBar
Prototype: 
```C
unsigned short PrintBar(PB* lpbar);
```
### API Function: DeleteBar
Prototype: 
```C
unsigned short DeleteBar(PB* lpbar);
```
### Example
There is an example to show that the using of this project.
```C
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "ConsoleProgresssBar.h"

#pragma comment(lib,"ConsoleProgresssBar.lib")

int main()
{
	PB bar;
	CreateBar(&bar, 256, 32, '#', ' ');
	for (int i = 1; i <= 256; i++) {
		Sleep(10);
		RefreshBar(&bar, i);
		PrintBar(&bar);
	}
    return 0;
}
```
