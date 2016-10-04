#!/bin/bash

## Wenn es einen Fehler gibt, breche das Skript ab
set -e
source ./funcs.sh

## SSH-Key erstellen

msg "SSH Key will be created, if not present..."

if [ ! -f ~/.ssh/id_rsa.pub ]; then
    msg "Creating SSH Key ..."
    ssh-keygen -b 4096
    msg "SSH Key created"
else
    msg "SSH Key already present"
fi

msg "Note: Your SSH Key have to be registered in your GITHUB-Account and your GITHUB-Account have to be granted access rights from supervisor!"
if askSure "Open GITHUB?"; then
  xdg-open "https://github.com/carpe-noctem-cassel"
fi

msg "GITHUB Repositories will be downloaded, if not present ..."

ghurl='git@github.com:carpe-noctem-cassel/'
# Repos to clone
repos='alica alica-plan-designer supplementary cnc-turtlebots'

## Ordnerstruktur erstellen, falls nicht vorhanden
mkdir -p ~/ttbws/src
cd ~/ttbws/src

for r in $repos; do
    if [ ! -d $r ]; then
        msg "Cloning repository $r"
        git clone $ghurl$r'.git'
    else
        msg "$r already exists!"
    fi
done


# Git einrichten
## gitconfig in Benutzerverzeichniss kopieren wenn noch nicht vorhanden oder übername gewünscht ist
if [ ! -f ~/.gitconfig ] || askSure "Use Gitconfig of CarpeNoctemCassel? (Existing ~/.gitconfig will be overwritten!)"; then
    cp ~/cnws/src/cnc-msl/configuration/gitconfig ~/.gitconfig
fi

## Benutzernamen und Email abfragen und eintragen
if askSure "Setup GIT-E-Mail and -Name?"; then
    getInput "Enter mailaddress for GIT" "email"
    sed -i "/email/c\\\temail = ${email}" ~/.gitconfig
    msg "Mailaddress set"

    getInput "Enter real name for GIT" "name"
    sed -i "/name/c\\\tname = ${name}" ~/.gitconfig
    msg "Username set"
fi
