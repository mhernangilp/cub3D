<h1 align="center">
	🎮 cub3D
</h1>

<p align="center">
	<b><i>My first RayCaster</i></b><br>
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
</h3>

---
<p align="center">
	<img width="800" alt="screenshot" src="https://github.com/mhernangilp/cub3D/assets/123759990/9d827368-af49-42a1-bf5a-f45bf29bb3f4">
</p>


## 💡 About the project

> _This project is a very small 3D maze.
Its purpose is to make you work with ray-casting, 3D textures and some other very basic gameplay elements._

	This project is inspired by the world-famous Wolfenstein 3D game, which
	was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to
	make a dynamic view inside a maze, in which you’ll have to find your way.
	You are going to use the school graphical library: the MiniLibX!
	This library was developed internally and includes basic necessary tools to open
	a window, create images and deal with keyboard and mouse events.

For more detailed information, look at the [**subject of this project**](https://github.com/mhernangilp/cub3D/blob/master/en.subject.cub3d.pdf).


## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling**

To compile, go to the project path and run:

```shell
$ make
```

## 📋 How to play

To play the 3D maze just need to launch it with the following shell command:

```shell
$ ./cub3D <map_name>.cub
```

I added some maps if you want to test the game, there are located in:

```shell
$ maps/valid
```

**Controls**

You can use WASD to move FORWARD, LEFT, BACKWARD or RIGHT respectively.

You can use the mouse or <- and -> keys to move player camera LEFT and RIGHT respectively.
To quit the game press ESC or click on the red cross of window.

**Maps**

You can use any map of your choice as long as you follow the next rules:

* The file extension must be `.cub`.
* The whole map limits must be a `1`.
* It can only have one player set by it's position N, W, S, E.
* Must have each orientation texture file and floor & ceiling color (see valid maps).
* Map characters allowed:

|  Character  |          Object          |
|:-----------:|:------------------------:|
|    *" "*    | Void                     |
|     *1*     | Wall                     |
|     *0*     | Empty                    |
|     *N*     | Player looking North     |
|     *W*     | Player looking West      |
|     *S*     | Player looking South     |
|     *E*     | Player looking East      |
