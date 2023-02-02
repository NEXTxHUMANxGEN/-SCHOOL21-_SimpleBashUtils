#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
TEST_FILE="text_file.txt"
TEST_FILE2="another_text_file.txt"
echo "" > log.txt

#..............one file......................

for var in  -v -c -l -n -h -s -o
do
          TEST1="$var $TEST_FILE"
          echo "as $TEST1"
          ./s21_grep as $TEST1 > s21_grep.txt
          grep as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done

for var in  -v -c -l -n -h -s -o
do
          TEST1="$var $TEST_FILE"
          echo "-e as $TEST1"
          ./s21_grep -e as $TEST1 > s21_grep.txt
          grep -e as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done

for var in  -v -c -l -n -h -s -o
do
          TEST1="$var $TEST_FILE"
          echo "-e as $TEST1 -f file_for_regex.txt" 
          ./s21_grep -e as $TEST1 -f file_for_regex.txt > s21_grep.txt
          grep -e as $TEST1 -f file_for_regex.txt > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1 -f file_for_regex" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
          TEST1="$var $var2 $TEST_FILE"
          echo "as $TEST1"
          ./s21_grep as $TEST1 > s21_grep.txt
          grep as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
          TEST1="$var $var2 $TEST_FILE"
          echo "-e as $TEST1"
          ./s21_grep -e as $TEST1 > s21_grep.txt
          grep -e as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
          TEST1="$var $var2 $TEST_FILE"
          echo "-e as $TEST1 -f file_for_regex.txt"
          ./s21_grep -e as $TEST1 -f file_for_regex.txt > s21_grep.txt
          grep -e as $TEST1 -f file_for_regex.txt > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1 -f file_for_regex" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
      for var3 in -v -c -l -n -h -s
      do
          TEST1="$var $var2 $var3 $TEST_FILE"
          echo "as $TEST1"
          ./s21_grep as $TEST1 > s21_grep.txt
          grep as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
      done
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
      for var3 in -v -c -l -n -h -s
      do
          TEST1="$var $var2 $var3 $TEST_FILE"
          echo "-e as $TEST1"
          ./s21_grep -e as $TEST1 > s21_grep.txt
          grep -e as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
      done
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
      for var3 in -v -c -l -n -h -s
      do
          TEST1="$var $var2 $var3 $TEST_FILE"
          echo "-e as $TEST1 -f file_for_regex.txt"
          ./s21_grep -e as $TEST1 -f file_for_regex.txt > s21_grep.txt
          grep -e as $TEST1 -f file_for_regex.txt > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1 -f file_for_regex" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
      done
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
      for var3 in -v -c -l -n -h -s
      do
          for var4 in -v -c -l -n -h -s
          do
          TEST1="$var $var2 $var3 $var4 $TEST_FILE"
          echo "as $TEST1"
          ./s21_grep as $TEST1 > s21_grep.txt
          grep as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
          done
      done
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
      for var3 in -v -c -l -n -h -s
      do
          for var4 in -v -c -l -n -h -s
          do
          TEST1="$var $var2 $var3 $var4 $TEST_FILE"
          echo "-e as $TEST1"
          ./s21_grep -e as $TEST1 > s21_grep.txt
          grep -e as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
          done
      done
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
      for var3 in -v -c -l -n -h -s
      do
          for var4 in -v -c -l -n -h -s
          do
          TEST1="$var $var2 $var3 $var4 $TEST_FILE"
          echo "-e as $TEST1 -f file_for_regex.txt"
          ./s21_grep -e as $TEST1 -f file_for_regex.txt > s21_grep.txt
          grep -e as $TEST1 -f file_for_regex.txt > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1 -f file_for_regex" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
          done
      done
  done
done

#..............two files......................

for var in  -v -c -l -n -h -s -o
do
          TEST1="$var $TEST_FILE $TEST_FILE2"
          echo "as $TEST1"
          ./s21_grep as $TEST1 > s21_grep.txt
          grep as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done

for var in  -v -c -l -n -h -s -o
do
          TEST1="$var $TEST_FILE $TEST_FILE2"
          echo "-e as $TEST1"
          ./s21_grep -e as $TEST1 > s21_grep.txt
          grep -e as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done

for var in  -v -c -l -n -h -s -o
do
          TEST1="$var $TEST_FILE $TEST_FILE2"
          echo "-e as $TEST1 -f file_for_regex.txt" 
          ./s21_grep -e as $TEST1 -f file_for_regex.txt > s21_grep.txt
          grep -e as $TEST1 -f file_for_regex.txt > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1 -f file_for_regex" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
          TEST1="$var $var2 $TEST_FILE $TEST_FILE2"
          echo "as $TEST1"
          ./s21_grep as $TEST1 > s21_grep.txt
          grep as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
          TEST1="$var $var2 $TEST_FILE $TEST_FILE2"
          echo "-e as $TEST1"
          ./s21_grep -e as $TEST1 > s21_grep.txt
          grep -e as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
          TEST1="$var $var2 $TEST_FILE $TEST_FILE2"
          echo "-e as $TEST1 -f file_for_regex.txt"
          ./s21_grep -e as $TEST1 -f file_for_regex.txt > s21_grep.txt
          grep -e as $TEST1 -f file_for_regex.txt > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1 -f file_for_regex" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
      for var3 in -v -c -l -n -h -s
      do
          TEST1="$var $var2 $var3 $TEST_FILE $TEST_FILE2"
          echo "as $TEST1"
          ./s21_grep as $TEST1 > s21_grep.txt
          grep as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
      done
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
      for var3 in -v -c -l -n -h -s
      do
          TEST1="$var $var2 $var3 $TEST_FILE $TEST_FILE2"
          echo "-e as $TEST1"
          ./s21_grep -e as $TEST1 > s21_grep.txt
          grep -e as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
      done
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
      for var3 in -v -c -l -n -h -s
      do
          TEST1="$var $var2 $var3 $TEST_FILE $TEST_FILE2"
          echo "-e as $TEST1 -f file_for_regex.txt"
          ./s21_grep -e as $TEST1 -f file_for_regex.txt > s21_grep.txt
          grep -e as $TEST1 -f file_for_regex.txt > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1 -f file_for_regex" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
      done
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
      for var3 in -v -c -l -n -h -s
      do
          for var4 in -v -c -l -n -h -s
          do
          TEST1="$var $var2 $var3 $var4 $TEST_FILE $TEST_FILE2"
          echo "as $TEST1"
          ./s21_grep as $TEST1 > s21_grep.txt
          grep as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
          done
      done
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
      for var3 in -v -c -l -n -h -s
      do
          for var4 in -v -c -l -n -h -s
          do
          TEST1="$var $var2 $var3 $var4 $TEST_FILE $TEST_FILE2"
          echo "-e as $TEST1"
          ./s21_grep -e as $TEST1 > s21_grep.txt
          grep -e as $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
          done
      done
  done
done

for var in -v -c -l -n -h -s
do
  for var2 in -v -c -l -n -h -s
  do
      for var3 in -v -c -l -n -h -s
      do
          for var4 in -v -c -l -n -h -s
          do
          TEST1="$var $var2 $var3 $var4 $TEST_FILE $TEST_FILE2"
          echo "-e as $TEST1 -f file_for_regex.txt"
          ./s21_grep -e as $TEST1 -f file_for_regex.txt > s21_grep.txt
          grep -e as $TEST1 -f file_for_regex.txt > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ] || ["$DIFF_RES" == "Files s21_grep.txt and grep.txt  are identical"];
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "-e as $TEST1 -f file_for_regex" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
          done
      done
  done
done

echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"
