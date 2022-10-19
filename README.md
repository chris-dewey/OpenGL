# OpenGL

Given an objective, I strategize my design around modular, digestable, bite-sized components.
In a graphic based application, building a base structure around establishing the key dependencies, window object, and
shaders, I created a simple vertex array and sent data to draw a simple triangle. As long as everything renders properly,
I apply textures, rerun the application to make sure textures are rendered properly, then expand the triangle array to
include vertices for a 3D object, such as a pyramid. I continue this process adding little at a time and rerunning to 
validate until I have confidence that each component is integrating as expected.

Next, I separate each of the application's tasks into classes and/or objects to segment, encapsulate, and abstract code
into reusable and more refined parts. Reusability, such as when loading textures or shaders, allows more than one object
to be instantiated and then called with customized, memorable, convienent naming conventions. This also reduces redundant
code and makes future modifications easier to manage.

All programming languages and tasks can follow a similar approach. Getting familiar with graphical applications and 
how much effort goes into creating 3D models, objects, assigning textures and normals, and setting shader properties
provides considerable appreciation for numerous applications we use on a regular basis, otherwise taking them for granted.

Although I do not currently envision designing or developing games or other graphical intensive applications, my approcah,
practice opportunities, and diversifying my knowledge about different types of applications makes these projects extremely
valuable to my progression as a developer.
