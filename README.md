# mp3corrector
Corrects id3 tags with ffmpeg on c++

## For what
I don't have an ability to use any music app like "google play music", "yandex music" and etc... so I download it on to my pc. I use "VkMusic" program for this, but it has one disadventage - id3 tags are empty very often (I think it depends on mp3 file, which has been loaded to vk by another user). If you try to search music on your phone it would be hard because of empty id3s
The feature of using VkMusic is that fact that it names mp3-files with standart pattern: <artist> - <song title>
Programm just parse name of the mp3 and sets 2 id3 tags: "artist" and "title".

## How to use
1) Clone the repo
2) Set the path to the ffmpeg and the path to the directory with music as arguments... or you can run prog without args
3) Run script
4) Wait for a long time

* It's recursive and also correct inner folders
* It creates new folder for corrected music files near the current music directory
* It's useless for 99,99% of people )))


