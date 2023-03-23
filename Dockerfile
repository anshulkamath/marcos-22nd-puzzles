FROM ubuntu:latest

RUN apt-get update && \
    apt-get -y install systemd init apport sudo git mercurial make gdb \
    build-essential libssl-dev zsh curl

RUN mkdir /usr/local/repos
WORKDIR /usr/local/repos

RUN git config --global user.name "" && \
    git config --global user.email ""

ENV GITHUB_PAT "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"

ENV REPO "https://docker:${GITHUB_PAT}@github.com/anshulkamath/marcos-22nd-puzzles.git"

RUN git clone ${REPO}

RUN mkdir /workspaces
WORKDIR /workspaces

COPY startup.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/startup.sh

ENTRYPOINT [ "/bin/bash" ]
