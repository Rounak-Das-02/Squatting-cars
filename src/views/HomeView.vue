<template>
  <div class="flex flex-col gap-6">
    <section>
      <h1>Squatty</h1>
      <h3>The squatting car</h3>
    </section>

    <section class="grid gap-4">
      <h2>This challenge requires 2 players.</h2>
      <h3>
        Position yourself towards the camera and start squatting to move the car. The faster you squat, the faster the car moves.
        First to reach the finish line wins!
      </h3>
    </section>

    <section class="grid gap-4">
      <div class="flex flex-col-reverse rounded-2xl gap-6 p-4 min-h-max border-dashed border-2">
        <div class="flex justify-center items-center">
          <div class="camera-button">
            <button
              type="button"
              class="bg-slate-300 p-4 rounded-2xl hover:scale-90 transition-transform"
              @click="toggleCamera"
            >
              <span v-if="!isCameraOpen" class="flex gap-4 items-center">
                <img src="../assets/icons/ic_camera.svg" />
                <h3>Start Camera</h3>
              </span>
              <span v-else class="flex gap-4 items-center">
                <img src="../assets/icons/ic_camera_close.svg" />
                <h3>Stop Camera</h3>
              </span>
            </button>
          </div>
        </div>
        <div>
          <video
            ref="camera"
            class="w-full bg-black object-cover rounded-xl"
            autoplay
          ></video>
        </div>
      </div>
    </section>
  </div>
</template>

<script>
// @ is an alias to /src
import axios from "axios";

export default {
  name: "HomeView",
  data() {
    return {
      msg: "",
      polling: null,
      isCameraOpen: false,
    };
  },
  methods: {
    getMessage() {
      const path = "http://localhost:5000";
      axios
        .get(path)
        .then((res) => {
          this.msg = res.data;
        })
        .catch((error) => {
          console.error(error);
        });
    },
    pollData() {
      this.polling = setInterval(() => {
        this.getMessage();
      }, 1);
    },
    startCameraStream() {
      const constraints = (window.constraints = {
        audio: false,
        video: true,
      });
      navigator.mediaDevices
        .getUserMedia(constraints)
        .then((stream) => {
          this.$refs.camera.srcObject = stream;
        })
        .catch((error) => {
          alert("Browser doesn't support or there is some errors." + error);
        });
    },
    stopCameraStream() {
      let tracks = this.$refs.camera.srcObject.getTracks();
      tracks.forEach((track) => {
        track.stop();
      });
    },
    toggleCamera() {
      if (this.isCameraOpen) {
        this.isCameraOpen = false;
        this.stopCameraStream();
      } else {
        this.isCameraOpen = true;
        this.startCameraStream();
      }
    },
  },
  created() {
    // this.pollData();
  },
  beforeDestroy() {
    clearInterval(this.polling);
  },
};
</script>
