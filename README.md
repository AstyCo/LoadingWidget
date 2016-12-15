# LoadingWidget

Пример использования смотри MainWindow в test.pro

## Управления процессами:
### HTask - класс задания, (Heave Task)
	
* HTaskCaller - отвечает за выполнение процесса
* HTaskBreaker - отвечает за отмену выполнения
		
	
### HTaskManager - управляет заданиями(которые HTask)
	
На данный момент поддерживается только 2 режима все асинхронно/все синхронно.
* HTaskManager::SynchronizedMode
	* HTaskManager::sync 
	* HTaskManager::async 
		
	
## Отображение:
* LoadingDialog - для одного процесса
* MultiTaskLoadingWidget - для нескольких процессов
	
_Если не закрывается - HTaskManager возможно удалился на стеке_
	
