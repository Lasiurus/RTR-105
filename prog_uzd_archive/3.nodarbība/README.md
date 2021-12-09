# 3.nodarbība - Basic programmu izveide un apstrāde
  
  
  
  * `echo $?` - Atrod "exit code" priekš pagājušās izpildītās komandas.
       * `0` - bez problēmām.
       * `127` - kautkas nepareizi.

  * `cat [filename]` - Izprintē faila saturu _sdout_.
       * `cat > [filename]` - Izveido jaunu failu un sāk tajā rakstīt. `Ctrl+C` - lai izietu.
  * `gcc` - Palaiž C compiler.
       * `gcc [filename] -o [outputfilename]` - Dod output failam konkrētu name un extension.
       * `gcc -save-temps [filename]` - Izveido .i .o .s failus par paliekošiem un izveido .exe vai .out, ja kods ir pareizs.
  * `./[filename]` - Pasaka shellam, kur precīzi meklēt attiecīgo failu, lai palaistu.
  * `mv [filename1] [filename2]` - Pārsaukt failu.

