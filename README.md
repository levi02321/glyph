# glyph #
A command line program for encryption purposes.

## Documentation ##
### How to Set-Up ###
If you want to use the program without modifiying any code, simply download
the repository, then add the bin/release directory to your PATH variable. After you
do that, you should be able to use the program by typing "glyph" into any command
prompt. (Note: this works in Windows only, as I haven't been able to access a
Linux system to compile it in).

### How to Use ###
After you have follow the above instructions and initiated the program, it will
ask you for input on which action you would like to take. Below are the actions
listed with a small message about their purpose and usage.

#### help ####
This option can only be used in the action prompt. It displays a link which will bring
you to this README page.

#### version ####
This option can only be used in the action prompt. It displays the current version
number of glyph.

#### encrypt ####
This option can only be used in the action prompt. It brings up another input prompt
which asks for the encryption algorithm you would like to use. Below are the accepted
values that this option accepts.

* caesar
Selects the Caesar cipher option. It will bring up two more prompts, asking for input
text and then for a key.

* beaufort
Selects the Beaufort cipher option. It will bring up two more prompts, asking for input
text and then for a key.

* a1z26
Selects the A1Z26 cipher option. It will bring up one more prompt, asking for input text.

* ascii-decimal
STILL IN DEVELOPMENT. Selects the ascii-decimal option. It will bring up one 
more prompt, asking for input text.

#### decrypt ####
This option can only be used in the action prompt. It brings up another input prompt
which asks for the encryption algorithm you would like to use.

* caesar
Selects the Caesar cipher option. It will bring up two more prompts, asking for input
text and then for a key.

* beaufort
Selects the Beaufort cipher option. It will bring up two more prompts, asking for input
text and then for a key.

* a1z26 
STILL IN DEVELOPMENT. Selects the A1Z26 cipher option. It will bring up one more 
prompt, asking for input text.

* ascii-decimal
STILL IN DEVELOPMENT. Selects the ascii-decimal option. It will bring up one 
more prompt, asking for input text.
