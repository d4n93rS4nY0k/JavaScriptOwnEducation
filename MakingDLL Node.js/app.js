const ffi = require("ffi");

// Convert JSString to CString
function TEXT(text) {
    return Buffer.from(`${text}\0`, "ucs2");
}

// Import user32
const user32 = new ffi.Library("user32", {
    "MessageBoxW": [
        "int32", ["int32", "string", "string", "int32"]
    ],
    "SetCursorPos": [
        "bool", ["int32", "int32"]
    ]
});

// Call the message box function
const OK_or_Cancel = user32.MessageBoxW(
    0, TEXT("Main.dll"), TEXT("Hello, World!"), 1
);

// Show the output of the message box
console.log(OK_or_Cancel);

// Set the cursor position
user32.SetCursorPos(0, 0);
