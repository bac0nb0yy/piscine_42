#!/bin/sh
id -G -n $FT_USER | tr -s ' ' ',' | tr -d '\n'
