Read about Heavy compiler [there](https://github.com/enzienaudio/hvcc.git). To use this image to compile your patch, do like so:

```bash
docker pull sidec/hvcc-c2js:latest
cd /to/dir/with/patch/you/want/to/compile
docker run -v $(pwd):/opt/hvcc/tmp sidec/hvcc-c2js:latest -o /opt/hvcc/tmp/NameOfYourPatch -n NameOfYourPatch /opt/hvcc/tmp/NameOfYourPatch.pd
```

This will generate NameOfYourPatch folder with a number of folders, among them js. You can test your build by running following command and then browsing in Firefox (tested) to http://localhost:8080:

```bash
cd ./NameOfYourPatch/js
python2.7 -m SimpleHTTPServer -p 8080
```
