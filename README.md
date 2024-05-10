数据存储在/tmp/testdb下

需要提前在/tmp目录下新建一个文件夹merge，用来暂存组装后的ldb文件，用完后系统会自动删除

执行文件在[leveldb所在路径]/pracitce下，demo.cc是写数据的代码文件，read.cc是读数据的代码文件。在该路径下执行./compile.sh会编译生成demo和read的可执行文件

执行./demo，会向leveldb中写入数据，在/tmp/testdb下有stripe1、stripe2、stripe3、stripe4、stripe5、stripe6六个文件夹，前四个用来存储ldb文件切割后的四个文件块，后两个用来存储生成的冗余文件块。

我写入的数据原本存储在000005.ldb之中，改变存储形式后被切割成了000005_1.stripe,000005_2.stripe,000005_3.stripe,000005_4.stripe。对应生成的冗余文件是000005_5.stripe,000005_6.stripe。任意删去两个文件，再执行./read，会恢复这两个文件，并打印出读取到的数据。
