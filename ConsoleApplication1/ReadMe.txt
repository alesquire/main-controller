Bugs

1. (done) Tonearm voltage works incorrectly- 0 value for full left and idle, and also for antiscate
2. Implement antiscate regulator and damper regulator
3. (done) Implement stroboscope
4. Implement reference tonearm output value
5. (done) Extend DutTimer library to use one time call functions
6. (done) Implement timers
	- delayed autostop
	- stroboscope
	- tonearm control onTimer 
7. Implement correct tonearm direction calculation- which output voltage correspond to LEFT and which to RIGHT
1. на транзистор микролифта нужен радиатор
2. нет поднимания микролифта при включении вертушки (возможно из-за временной схемы инициализации)
3. Подсветка кнопок скорости работает неверно. Нужно менять транзисторы
4. триггер шмитта не работает на датчики миколифта. нужен конденсатор
5. поставить кондексаторы на кнопки тонарма и скорости
6. переписать логику определния положения тонарма. оказывается нельзя вешить два прерывания на один пин