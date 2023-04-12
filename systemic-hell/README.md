# Docker How-to

Hello, Paco. Welcome to your first (of several) systems puzzles.
I do hope you're excited to get elbow deep in your computer.
Before we begin, though, we need to ensure that our environments are compatible.
Hence, you need to download a docker image and run it.

I have already created an image for you.
Follow the steps below to download the built image and run it in a container:

```sh
# Download the image from GitHub container registry
docker pull ghcr.io/anshulkamath/marcos-22nd:latest

# Build the image
docker run -it --security-opt "seccomp=unconfined" --cap-add SYS_PTRACE -v $(pwd):/workspaces marcos-22nd
```

The `-v` argument is to mount your filesystem to the docker container.
If you are not in your working directory then change `$(pwd)` to the path of your
working directory.

Alternatively, if you'd like to avoid running all of the above, you can use the given `docker-compose.yml` and run `docker-compose run marcos-22nd` (there might be permissions issues though, so let me know if you need help).

Once you're in the docker container, you can treat it as a normal shell and develop as you'd like. Make sure to keep this docker image until the puzzles are over - you're going to be back here a couple times :)
