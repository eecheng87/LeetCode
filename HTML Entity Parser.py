class Solution(object):
    def entityParser(self, text):
        """
        :type text: str
        :rtype: str
        """
        string = text;
        string = string.replace("&quot;","\"")
        string = string.replace("&apos;","\'")
        string = string.replace("&amp;","&")
        string = string.replace("&gt;",">")
        string = string.replace("&lt;","<")
        string = string.replace("&frasl;","/") 
        return string
        