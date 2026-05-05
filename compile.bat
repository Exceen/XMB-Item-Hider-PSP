PATH = c:/pspsdk/bin
make clean
make CONFIG_5xx=1
mkdir 5xx
copy xmbih.prx 5xx\xmbih.prx /y
make clean
make CONFIG_6xx=1
mkdir 6xx
copy xmbih.prx 6xx\xmbih.prx /y
make clean
pause