#! /bin/bash

export DOCKER_COMPOSE='../docker-compose.yml'
export MARCOS_DOCKER_SCRIPT='https://raw.githubusercontent.com/marcos-acosta/macos-birthday/main/run-docker.sh'
export MARCOS_EVAN_CODE='https://raw.githubusercontent.com/marcos-acosta/macos-birthday/main/puzzle-6/board_processing.py'
export GITHUB_TOKEN='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'

if [[ ! -e $DOCKER_COMPOSE ]]; then
  echo "Please put me in my puzzle folder and execute me from there."
  return
fi

echo -e "Very sensitive information downloaded. Preview found here:\n"
curl -s -H "Authorization: token $GITHUB_TOKEN" $MARCOS_EVAN_CODE | head -n 10
echo -e "\n"

echo -e "Starting run-docker script. Figure it out from there:\n"
source <(curl -s -H "Authorization: token $GITHUB_TOKEN" $MARCOS_DOCKER_SCRIPT)

if [[ $? -ne 0 ]]; then
  echo "Something broke when trying to execute Marcos's run-docker script. Please make sure that all paths are correct"
fi
