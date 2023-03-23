FROM ubuntu:latest

RUN apt-get update && \
    apt-get -y install systemd init apport sudo git mercurial make gdb \
    build-essential libssl-dev zsh curl

RUN mkdir /usr/local/repos
WORKDIR /usr/local/repos

ARG GITHUB_PAT
RUN git config --global user.name "" && \
    git config --global user.email "" && \
    git config --global url."https://docker:${GITHUB_PAT}@github.com".insteadOf "https://github.com"

ENV REPO "https://docker:${GITHUB_PAT}@github.com/anshulkamath/marcos-22nd-puzzles.git"

RUN git clone ${REPO}

RUN mkdir /workspaces
WORKDIR /workspaces

COPY startup.sh /usr/local/bin/
RUN /usr/local/bin/startup.sh

ENTRYPOINT [ "/usr/local/bin/startup.sh" ]
