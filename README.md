# example_opencv ROS_package

## Descripción general
Tutorial básico del uso de OpenCV dentro de ROS comentado para que sea más complensible para los programadores que se están iniciando en ROS.

## Proceso de instalación
Se considera que la computadora del usuario ya tiene correctamente instalado ROS, GIT y que ya tiene la carpeta de `catkin_ws` correctamente inicializada.
Para asegurarse que se tiene un dispositivo de video, ejecutar en una Terminal:
```
$ cheese
```
Deberá de ver la imagen de la cámara. En caso contrario significa que no tiene una cámara de video correctamente instalada. 

Para asegurarse que se tiene correctamente instalado OpenCV, ejecutar la siguiente instrucción en una Terminal:
```
$ pkg-config –-modversion opencv
```
Debe responder con la versión de OpenCV. En caso que no tenga instalado OpenCV, ejecutar:
```
sudo apt-get install ros-kinetic-vision-opencv libopencv-dev python-opencv
```
En una Terminal ejecutar las siguientes instrucciones:
```
$ cd ~/catkin_ws/src
$ git clone https://github.com/aaceves/example_opencv.git
$ cd ~/catkin_ws
$ catkin build
$ source devel/setup.bash
```
El proceso de compilación debe terminar sin errores.

## Ejemplo de ejecución

En tres Terminales diferentes ejecutar cada una de las siguientes lineas, en donde  `<path/file.jpg>` se sustituye por la dirección y nombre exacto de un archivo de imagen jpg:
```
$ roscore
$ rosrun example_opencv showimage <path/file.jpg>
$ rosrun example_opencv showcam
```

## Autores y colaboradores
Este paquete fue preparado por el Dr. Alejandro Aceves-López usando las referencias abajo citadas para que sea más comprensible a los programadores nuevos de ROS.

## Referencias
1. Anónimo, “OpenCV Tutorials version 3.2.0”, publicado el 23 dic 2016, (link)[https://docs.opencv.org/3.2.0/d9/df8/tutorial_root.html]   
2. Kushal Jaligama, "ROS-OpenCV-Example", 21 Jan 2018 (link)[https://github.com/umigv/ROS-OpenCV-Example]
