# Docker How-to

Hello, Paco. Welcome to your first (of several) systems puzzles.
I do hope you're excited to get elbow deep in your computer.
Before we begin, though, we need to ensure that our environments are compatible.
Hence, you need to download a Docker image and run it.

I have already created an image for you.
Please set up your file directory with your `docker-compose.yml` in the project root, along with all `.zip`s and folders.
Then, `cd` into your project root.
Make sure that you have Docker downloaded and open in the background, and run `docker-compose run marcos-22nd`.
Let me know if this doesn't work.

Once you're in the Docker container, you can treat it as a normal shell and develop as you'd like.
Your project's root has been mounted to the container, so any changes you make on your local machine will be reflected in the Docker virtual machine.
Make sure to keep this Docker image until the puzzles are over - you're going to be back here a couple times :)
